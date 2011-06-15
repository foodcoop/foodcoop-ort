$(function() {

/**
* Convert input buttons to span for cufon. Hide the input, append the div, span
* and button value, bind the click.
*/

	$('input.button').each(function(){
		$(this).hide().after('<div class="button-rounded">').next('div.button-rounded').html('<span>' + $(this).val() + '</span>').click(function(){
			 $(this).prev('input.button').click();
		});
	});


/////////////////////////////
//
// slightly simpler disclosure triangles
//
//	  outer container any block element with class QA
//   question container is <a> with class of "Q"
//   answer container is any block element with class of "A"
//
// dependent upon gfx: /misc/menu-expanded.png & menu-collapsed.png
//

	$(".QA").each(function(){
		var qa = $(this);
		var q = $(this).children(".Q");
		var a = $(this).children(".A");

		qa.wrapInner("<ul class='qa_ul'/>");
		a.wrap("<li class='a_li' style='padding:0px; margin-left:10px;'/>");

		var ap = a.parent();
		ap.isOpen = true;
		
		q.wrap("<li class='q_li' style='list-style-type: none, list-style-position: outside; padding:0px; margin-left:10px'/>").attr("href","javascript:void 0");
		q.click(function(){toggle()});

		var qp = q.parent();
		
		function toggle(quick){
			if (ap.isOpen){
				ap.hide(quick?0:"medium");
				qp.css("list-style-image","url(/misc/menu-collapsed.png)");
			} else {
				ap.show("medium");
				qp.css("list-style-image","url(/misc/menu-expanded.png)");
			}
			ap.isOpen = !ap.isOpen;
		}
		
		toggle(true);
		
	});
	
//
/////////////////////////////

});

// Email field matching
$(document).ready(function(){
  $("input#edit-mail2").blur(function(){
    if ($("input#edit-mail").val() != $("input#edit-mail2").val()) {
      $("input#edit-mail").addClass('error');
      $("input#edit-mail2").addClass('error');
      if ($("#emails .fields").next().hasClass("email-match-warning")) {
        $("#emails .fields").next().remove();
      }
      $("form #emails").append('<div class="email-match-warning" style="color:red;">Email addresses do not match.  Please retype them to make sure they are the same.</div>');
    }
    else {
      $("input#edit-mail").removeClass('error');
      $("input#edit-mail2").removeClass('error');
      $(".email-match-warning").remove();
    }
  });
});


// open/close the welcom bubble
$(function(){
	$("div#psfc_welcom_new .close").show();
	$("div#psfc_welcom_new .close").click(function() {
		// $("div#psfc_welcom_new").remove();
		// animate the welcom bubble closed
		$("div#psfc_welcom_new").animate({"margin-top":"-500px"}, 600, null, function(){$(this).remove();} );
	});
	// animate the welcom bubble open
	$("div#psfc_welcom_new").css({"margin-top":"-500px"}).animate({"margin-top":"0px"},1000);
});