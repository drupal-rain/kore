
(function($) {
  Drupal.behaviors.koreDatetimeAgo = {
    attach: function (context, settings) {
      if (typeof Foundation == 'undefined') return;

      $(".datetime-ago").each(function (index, element) {
        settings = Foundation.utils.data_options($(element));
        text = moment(settings.timestamp, "X").fromNow();
        $(element).text(text);
      })
    }
  }
})(jQuery);
