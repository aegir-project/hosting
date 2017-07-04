(function($) {
window.onload=function() {

    // If #hostingTasks object is available, initiate a Vue.
    if ($('#hostingTasks').length) {
        var hostingTasksVue = new Vue({
            el: '#hostingTasks',
            data: {
                tasksUrl: Drupal.settings.hostingTasks.url,
                tasks: Drupal.settings.hostingTasks.tasks,
                availableTasks: Drupal.settings.availableTasks,
                timeout: Drupal.settings.hostingTasks.refreshTimeout
            },
            created: function () {

                // Update time elements from their DOM timestamps.
                $('time.timeago', '#hostingTasks').timeago("updateFromDOM");

                // Set timeout to reload data.
                setTimeout(this.fetchData, this.timeout);
            },
            updated: function () {

                // Clear html and title attributes from elements with empty datetime.
                $('time.timeago[datetime=""]').html('').attr('title')

                // Update time elements from their DOM timestamps.
                $('time.timeago', '#hostingTasks').timeago("updateFromDOM");
            },
            methods: {
                fetchData: function () {
                    // Thanks to the GitHub Commits example: https://vuejs.org/examples/commits.html
                    var xhr = new XMLHttpRequest()
                    var self = this
                    xhr.open('GET', self.tasksUrl)
                    xhr.onload = function () {
                        var data = JSON.parse(xhr.responseText)

                        // Replace vue data with new data.
                        if (data.tasks) {
                            self.tasks = data.tasks
                        }
                        if (data.availableTasks) {
                            self.availableTasks = data.availableTasks;
                        }
                    }
                    xhr.send()
                    setTimeout(this.fetchData, this.timeout);
                }
            }
        });
    }
}

    // Drupal.behaviors.hostingTimeAgo = {
    //     attach: function (context, settings) {
    //         $.timeago.settings.refreshMillis = 1000;
    //         $.timeago.settings.strings = {
    //             prefixAgo: null,
    //             prefixFromNow: null,
    //             suffixAgo: "ago",
    //             suffixFromNow: "from now",
    //             allowFuture: true,
    //             inPast: 'any moment now',
    //             seconds: "%d sec",
    //             minute: "1 min",
    //             minutes: "%d min",
    //             hour: "1 hr",
    //             hours: "%d hrs",
    //             day: "1 day",
    //             days: "%d days",
    //             month: "1 month",
    //             months: "%d months",
    //             year: "1 year",
    //             years: "%d years",
    //             wordSeparator: " ",
    //             numbers: []
    //         }
    //         $(".timeago", context).timeago();
    //     }
    // }
}(jQuery));

    //
    // Drupal.behaviors.hostingTasks = {
    //     attach: function (context, settings) {
    //
    //         // Attach to the global hosting tasks block.
    //         if ($('#hostingTasks').length > 0) {
    //             Drupal.settings.hostingTasks.vue = new Vue({
    //                 el: '#hostingTasks',
    //                 data: {
    //                     tasks: Drupal.settings.hostingTasks.tasks,
    //                 },
    //                 watch: {
    //
    //                     // Watch tasks for changes: update timeago if timestamp changes
    //                     tasks: function (tasks, oldTasks) {
    //
    //                         // Clear HTML on all time elements without datetime.
    //                         setTimeout(function () {
    //                             $('time.timeago[datetime=""]').html('').attr('title');
    //                         }, 10);
    //
    //                         // Check all tasks, if timestamp changed, updateFromDOM
    //                         for (var i = 0, len = tasks.length; i < len; i++) {
    //                             var task = tasks[i];
    //                             if (task.timestamp != oldTasks[i].timestamp || task.timestamp_executed != oldTasks[i].timestamp_executed) {
    //                                 // Set a tiny timeout so timeago reset happens after DOM update.
    //                                 setTimeout(function () {
    //                                     $("time.timeago").timeago("updateFromDOM");
    //                                 }, 10);
    //                                 return;
    //                             }
    //                         }
    //                     },
    //                 }
    //             });
    //         }
    //
    //         // Attach to the available_tasks block, if there is one.
    //         if ($('#hostingAvailableTasks').length > 0) {
    //             Drupal.settings.hostingTasks.vueAvailable = new Vue({
    //                 el: '#hostingAvailableTasks',
    //                 data: {
    //                     tasks: Drupal.settings.hostingAvailableTasks,
    //                 },
    //             });
    //
    //         }
    //
    //         setTimeout("Drupal.behaviors.hostingTasks.checkTasks()", settings.hostingTasks.refreshTimeout);
    //     },
    //     checkTasks: function () {
    //         var url = Drupal.settings.hostingTasks.url;
    //         $.getJSON(url, function (data) {
    //
    //             // Replace vue data with new data.
    //             if (data.tasks && Drupal.settings.hostingTasks.vue) {
    //                 Drupal.settings.hostingTasks.vue.tasks = data.tasks;
    //             }
    //             if (data.availableTasks &&  Drupal.settings.hostingTasks.vueAvailable) {
    //               Drupal.settings.hostingTasks.vueAvailable.tasks = data.availableTasks;
    //             }
    //
    //             // Stop if needed.
    //             if (Drupal.settings.hostingTasks.halt != true) {
    //                 setTimeout("Drupal.behaviors.hostingTasks.checkTasks()", Drupal.settings.hostingTasks.refreshTimeout);
    //             }
    //         });
    //     },
    // };
    //
    // Drupal.behaviors.hostingTimeAgo = {
    //     attach: function (context, settings) {
    //         $.timeago.settings.refreshMillis = 1000;
    //         $.timeago.settings.strings = {
    //             prefixAgo: null,
    //             prefixFromNow: null,
    //             suffixAgo: "ago",
    //             suffixFromNow: "from now",
    //             allowFuture: true,
    //             inPast: 'any moment now',
    //             seconds: "%d sec",
    //             minute: "1 min",
    //             minutes: "%d min",
    //             hour: "1 hr",
    //             hours: "%d hrs",
    //             day: "1 day",
    //             days: "%d days",
    //             month: "1 month",
    //             months: "%d months",
    //             year: "1 year",
    //             years: "%d years",
    //             wordSeparator: " ",
    //             numbers: []
    //         }
    //         $(".timeago", context).timeago();
    //     }
    // }
// }(jQuery));

// (function($) {
//
// hostingTaskRefreshList = function() {
//   if (!Drupal.settings.hostingTaskRefresh.nid) {
//     return null;
//   }
//
//   var hostingTaskListRefreshCallback = function(data, responseText) {
//     // If the node has been modified, reload the whole page.
//     if (Drupal.settings.hostingTaskRefresh.changed < data.changed) {
//       // only reload if there is no modal frame currently open
//       if ($(document).data('hostingOpenModalFrame') != true) {
//         // If a specific URL was specified, go there.
//         if (data.navigate_url) {
//           document.location = data.navigate_url;
//         }
//         // Fall back to just doing a reload of the current page.
//         else {
//           document.location.reload();
//         }
//       }
//     }
//     else {
//       $("#hosting-task-list").html(data.markup);
//
//       hostingTaskBindButtons('#hosting-task-list');
//       setTimeout("hostingTaskRefreshList()", Drupal.settings.hostingTaskRefresh.refreshTimeout);
//     }
//   }
//
//   hostingTaskAddOverlay('#hosting-task-list');
//   $.get(Drupal.settings.basePath + 'hosting/tasks/' + Drupal.settings.hostingTaskRefresh.nid + '/list', null, hostingTaskListRefreshCallback , 'json' );
// }
//
//
// function hostingTaskAddOverlay(elem) {
//   $(elem).prepend('<div class="hosting-overlay"><div class="hosting-throbber"></div></div>');
// }
//
//
// hostingTaskRefreshQueueBlock = function() {
//   if (Drupal.settings.hostingTaskRefresh.queueBlock != 1) {
//     return null;
//   }
//
//   var hostingTaskQueueRefreshCallback = function(data, responseText) {
//     // $("#block-views-hosting-task-list-block .content").html(data.markup);
//     //
//     // hostingTaskBindButtons('#block-views-hosting-task-list-block');
//     setTimeout("hostingTaskRefreshQueueBlock()", Drupal.settings.hostingTaskRefresh.refreshTimeout);
//   }
//
//   // hostingTaskAddOverlay('#block-views-hosting-task-list-block .view-content');
//   $.get(Drupal.settings.basePath + 'hosting/tasks/queue', null, hostingTaskQueueRefreshCallback , 'json');
// }
//
// $(document).ready(function() {
//   $(document).data('hostingOpenModalFrame', false);
//   setTimeout("hostingTaskRefreshList()", Drupal.settings.hostingTaskRefresh.refreshTimeout);
//   setTimeout("hostingTaskRefreshQueueBlock()", Drupal.settings.hostingTaskRefresh.refreshTimeout);
//   hostingTaskBindButtons($(this));
//   $('#hosting-task-confirm-form-actions a').click(function() {
//     if (parent.Drupal.modalFrame.isOpen) {
//       setTimeout(function() { parent.Drupal.modalFrame.close({}, {}); }, 1);
//       return false;
//     }
//   });
//
// });
//
// hostingTaskBindButtons = function(elem) {
//   $('.hosting-button-dialog', elem).click(function() {
//       $(document).data('hostingOpenModalFrame', true)
//      var options = {
//         url : Drupal.settings.basePath + 'hosting/js' + $(this).attr('href'),
//         draggable : false,
//         width : 600,
//         height : 150,
//         onSubmit : function() {
//           $(document).data('hostingOpenModalFrame', false)
//           hostingTaskRefreshQueueBlock();
//           hostingTaskRefreshList();
//         }
//       }
//       Drupal.modalFrame.open(options);
//       return false;
//    });
// }
//
//
// })(jQuery);
