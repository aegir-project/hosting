(function($) {

Drupal.behaviors.hostingTaskLogAttach = {
  attach : function() {
    $('.hosting-summary-expand').click(
      function() {
        $(this).parent().toggle();
        $('.hosting-task-full', $(this).parent().parent()).toggle();
      }
    );
  }
}

// Close the an open overlay window when hitting the ESC key
// Example from https://www.drupal.org/node/963988
// TODO make it configurable
$(document).keyup(function(e) {
    if (e.keyCode == 27) { $('#overlay-close').click(); }
});

})(jQuery);