/**
* Convert input buttons to span for cufon. Hide the input, append the div, span
* and button value, bind the click.
*/
$(document).ready(function() {
  $('input.button').each(function(){
      $(this).hide().after('<div class="button-rounded">').next('div.button-rounded').html('<span>' + $(this).val() + '</span>').click(function(){
          $(this).prev('input.button').click();
      });
  });
});