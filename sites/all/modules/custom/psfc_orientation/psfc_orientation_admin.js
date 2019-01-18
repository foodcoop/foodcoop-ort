jQuery(document).ready(function() {
  jQuery("#psfc-admin-form .view-id-orientation_admin .date-display-single").each(function() {
    console.log(jQuery(this).attr("content"));
    var now = new Date(jQuery.now());
    var ort_date = new Date(jQuery(this).attr("content")).getTime();
    if (now > ort_date) {
      jQuery(this).css("text-decoration", "line-through");
    }
  });
});
