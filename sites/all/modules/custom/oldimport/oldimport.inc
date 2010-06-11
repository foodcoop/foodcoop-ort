<?php

	function oldimport_admin_settings(){
		$form["instructions"] = array(
			"#type" => "item",
			"#value" => "Use this to import old content from the soon-to-be-former site. This is a non-destructive action: no old pages will be changed on the old site; no new pages will be changed on the new site. Old pages will be imported into the same place each time the import is run, and can be manipulated, changed, deleted, or otherwise messed-up without fear (just import a fresh copy).",
		);
	

		$form["submit"] = array(
			"#type" => "submit",
			"#value" => t("Import Old Coop Data"),
		);
		return $form;
	}

	function oldimport_admin_settings_submit($form, $form_state){

	// $delta_nid = db_result(db_query("select nid from {node} order by nid desc limit 1")) + 100;
	// $delta_vid = db_result(db_query("select vid from {node_revisions} order by vid desc limit 1")) + 100;

		$delta_nid = 100;
		$delta_vid = 100;
		$menu_delta = 1000;

		db_set_active("old");
		$results = db_query("select * from coopPages where pageStatus = 1 order by parentID, pageOrder, pageID");
		db_set_active("default");
		$menu = array();

		while($row = db_fetch_array($results)){
			
			$nid = $row["pageID"] + $delta_nid;
			$vid = $row["pageID"] + $delta_vid;
			$parent = $row["parentID"] > 0 ? $row["parentID"] + $delta_nid : 0;
			$order = $row["pageOrder"];
			$now = time();
			$title = $row["pageTitle"];
			$content = $row["pageContent"];
			$format = $row["pageType"];
			$link =  $row["pageLink"];
			$mlid = $nid + $menu_delta;
			$plid = $parent > 0 ? $parent + $menu_delta : 0;
			
			db_query("replace into {node} values ($nid, $vid, 'page', 'en', '%s', 1, 1, $now, $now,0,0,0,0,0,0)",$title);
			db_query("replace into {node_revisions} values ($nid, $vid, 1, '%s', '%s', '', '', $now, $format)",$title, $content);
			
			$menu[$mlid] = array(
				"menu_name" => "main", 
				"mlid"=> $mlid,
				"plid" => $plid,
				"link_path" => "node/$nid",
				"router_path" => "node/%",
				"link_title" => $link,
				"options" => "a:0:{}",
				"module" => "menu",
				//"hidden" => 0,
				//"external" => 0,
				"has_children" => 0,
				//"expanded" => 0,
				"weight" => $order,
				"depth" => 1,
				//"customized" => 0,
				//"updated" => 0,
				"tree_children" => array(),
				"tree_path" => array(),
				"p1" => 0,
				"p2" => 0,
				"p3" => 0,
				"p4"=> 0,
				"p5" => 0,
				"p6" => 0,
				"p7" => 0,
				"p8" => 0,
				"p9" => 0,
			);
		}

		foreach ($menu as $id => $item){
			$parent_id = $item["plid"];
			if ($parent_id){
				$menu[$parent_id]["tree_children"] []= $id;
				$menu[$parent_id]["has_children"] = 1;
				$menu[$id]["depth"] = $menu[$parent_id]["depth"] + 1;
				$menu[$id]["tree_path"] = array_merge($menu[$parent_id]["tree_path"], array($id));
			} else {
				$menu[$id]["tree_path"] = array($id);
			}
		}

		foreach ($menu as $id => $item){
			$parent_id = $item["plid"];
			if ($parent_id){
				$menu[$id]["depth"] = $menu[$parent_id]["depth"] + 1;
				$menu[$id]["tree_path"] = array_merge($menu[$parent_id]["tree_path"], array($id));
			}
			$path =& $menu[$id]["tree_path"];
			foreach ($path as $pidx => $p){
				$menu[$id]["p".($pidx+1)] = $p;
			}
		}

		$rows = array();
		foreach ($menu as $id => $item){
			unset($menu[$id]["tree_path"]);
			unset($menu[$id]["tree_children"]);
			// db_query("replace into {menu_links} values ($nid, $vid, 1, '%s', '%s', '', '', $now, $format)",$title, $content);
			$rows[]= ' ("'.implode('", "',$menu[$id]).'") ';
		}
		$query = "replace into menu_links ( ".implode(", ",array_keys(end($menu)))." ) values ".implode(", ",$rows);
		
		// dangerous: had to use raw query interface because of nasty curly quote escaping!
		_db_query($query);
		// drupal_set_message("Query: ".$query);
		drupal_set_message("Imported ".count($menu)." pages!");
		drupal_set_message("Here's the menu array: ".pr($menu,true));
		
	}
	

	function pr(&$t, $ret_string = false){
		$out = "<pre>".print_r($t,true)."</pre>";
		if ($ret_string) return $out;
		else print $out;
	}

?>
