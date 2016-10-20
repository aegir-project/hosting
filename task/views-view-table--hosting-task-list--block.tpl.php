<?php

/**
 * @file
 * Template to display a view as a table.
 *
 * - $title : The title of this group of rows.  May be empty.
 * - $header: An array of header labels keyed by field id.
 * - $caption: The caption for this table. May be empty.
 * - $header_classes: An array of header classes keyed by field id.
 * - $fields: An array of CSS IDs to use for each field id.
 * - $classes: A class or classes to apply to the table, based on settings.
 * - $row_classes: An array of classes to apply to each row, indexed by row
 *   number. This matches the index in $rows.
 * - $rows: An array of row items. Each row is an array of content.
 *   $rows are keyed by row number, fields within rows are keyed by field ID.
 * - $field_classes: An array of classes to apply to each field, indexed by
 *   field id, then row number. This matches the index in $rows.
 * @ingroup views_templates
 */
?>

<table <?php if ($classes) { print 'class="'. $classes . '" '; } ?><?php print $attributes; ?> id="hostingTasks">
  <?php if (!empty($title) || !empty($caption)) : ?>
    <caption><?php print $caption . $title; ?></caption>
  <?php endif; ?>
  <?php if (!empty($header)) : ?>
    <thead>
    <tr>
      <?php foreach ($header as $field => $label): ?>
        <th <?php if ($header_classes[$field]) { print 'class="'. $header_classes[$field] . '" '; } ?> scope="col">
          <?php print $label; ?>
        </th>
      <?php endforeach; ?>
    </tr>
    </thead>
  <?php endif; ?>
  <tbody>
    <template v-for="task in tasks">
    <tr v-bind:class="task.status_class">
      <td class="hosting-status">
        <span class="views-field-task-type">{{ task.hosting_task_task_type }} {{ task.node_hosting_task_type }}:</span> <a class="reference" v-bind:href="task.ref_url">{{ task.node_hosting_task_title }}</a>
        <time class="timeago" v-bind:datetime="task.timestamp">{{ task.timestamp }}</time>
      </td>
      <td class="views-field views-field-nid hosting-actions">
        <a v-bind:href="task.task_url" class="hosting-button-enabled hosting-button-log hosting-button-dialog">{{ task.task_link_text }}</a>
      </td>
    </tr>
    </template>
  </tbody>
</table>
