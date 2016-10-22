<table class="hosting-table" id="hostingAvailableTasks">
  <thead>
    <tr>
        <th scope="col">
          <?php print t('Tasks'); ?>
        </th>
        <th scope="col">
          <?php print t('Actions'); ?>
        </th>
    </tr>
  </thead>
  <tbody>

    <noscript>
      <?php foreach ($tasks as $task_type => $task):
        $task = (object) $task;

        // Skip hidden tasks.
        if ($task->hidden) {
          continue;
        }

        ?>
      <tr class="<?php print $task->class; ?>">
        <td class="hosting-status">
          <?php print $task->title ?>
        </td>
        <td class="hosting-actions">

          <?php if ($task->view_link):
            $task = (object) $task;
            ?>
          <!-- View Link -->
          <a
            href="<?php print $task->view_link['url']; ?>"
            title="<?php print $task->view_link['title']; ?>"
            class="hosting-button-enabled hosting-button-log hosting-button-dialog">
            <?php print $task->view_link_text; ?>
          </a>
          <?php else: ?>
          <span class='hosting-button-disabled'>
            <?php print $task->view_link_text; ?>
          </span>
          <?php endif; ?>

          <?php if ($task->run_link):
            $task = (object) $task;
            ?>
          <!-- Run Link -->
          <a
            href="<?php print $task->run_link['url']; ?>"
            title="<?php print $task->run_link['title']; ?>"
            class="hosting-button-enabled hosting-button-log hosting-button-dialog">
            <?php print $task->run_link['text']; ?>
          </a>
          <?php else: ?>
          <span class='hosting-button-disabled'>
            <?php print $task->run_link['text']; ?>
          </span>
          <?php endif; ?>
        </td>
      </tr>
      <?php endforeach; ?>
    </noscript>

    <template v-for="task in tasks">

    <tr v-bind:class="task.class" v-if="!task.hidden">
      <td class="hosting-status">
        {{ task.title }}
      </td>
      <td class="hosting-actions">

        <!-- View Link -->
        <a
          v-if="task.view_link"
          v-bind:href="task.view_link.url"
          v-bind:title="task.view_link.title"
          class="hosting-button-enabled hosting-button-log hosting-button-dialog">
            {{ task.view_link.text }}
        </a>
        <span
          v-if="!task.view_link"
          class='hosting-button-disabled'>
          {{ task.view_link_text }}
        </span>

        <!-- Run Link -->
        <a
          v-if="task.task_permitted"
          v-bind:href="task.run_link.url"
          v-bind:title="task.run_link.title"
          class="hosting-button-enabled hosting-button-run hosting-button-dialog">
            {{ task.run_link.text }}
        </a>

        <span
          v-if="!task.task_permitted"
          class='hosting-button-disabled'>
          {{ task.run_link.text }}
        </span>

        <!-- Cancel Link -->
        <a
          v-if="task.cancel_link"
          v-bind:href="task.cancel_link.url"
          v-bind:title="task.cancel_link.title"
          class="hosting-button-enabled hosting-button-stop hosting-button-dialog">
            {{ task.cancel_link.text }}
        </a>
      </td>
    </tr>
    </template>

  </tbody>
  </table>