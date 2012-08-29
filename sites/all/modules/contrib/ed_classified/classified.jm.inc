<?php

function jm_classified_reply($node) {

	
	
	if ($node->type != "classified"){
		drupal_set_message("You can only reply to shift swap ads.", "error");
		drupal_goto("node/".$node->nid);
		return;
	}
	
	$reply = trim(@$_POST["swap_reply_msg"]);
	
	if (!$reply){
		drupal_set_message("If you wish to reply, please say something in the reply box, below.","error");
		drupal_goto("node/".$node->nid);
		return;	
	}
	
	$my_user = user_load($node->uid);
	global $user, $base_url;
	
	$to_email = $my_user->mail;
	$from_email = $user->mail;
	$from_name = $user->name;
	$from_url = $base_url."/user/".$user->uid;
	
	$title = $node->title;
	$subject = "Coop Shift Swap Reply";

	$msg = array();
	$msg[] = "Coop member $from_name ($base_url/user/".$user->uid.") replied to your shift swap ad entitled '$title' ($base_url/node/".$node->nid."):";
	$msg[] = "\n$reply\n";
	$msg[] = "Please respond to them at their email address: $from_email.";
	$msg[] = "--------------------\nThe PSFC Swap-o-matic!\nSee all of your current swap ads at $base_url/user/".$my_user->uid."/classified or browse all the ads at $base_url/swap.";

	$msg = implode("\n\n",$msg);
	
	// $happy = mail($to_email, $subject, $msg, "From: ".$from_email."\r\nReply-to: ".$from_email);
	$happy = mail($to_email, $subject, $msg, "From: ".$from_email."\r\nReply-to: ".$from_email);
	
	if ($happy) {
		drupal_set_message("Thanks! Your reply will be sent via email (".date("r").")");
		watchdog("classified",$msg);
	} else {
		drupal_set_message("There was a problem sending your reply email; please try again in a little while.", "error");
		watchdog("classified","error trying to email: ".$msg, null, WATCHDOG_ERROR);
	}
	
	drupal_goto("node/".$node->nid);
	
// 	return "<pre>Replying!
// 		Happy: $happy
// 		To: [$to_email]
// 		From: [$from_email]
// 		Subject: [$subject]
// 		Message : [[$msg]]
// 	</pre>";

}
