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
    <tr v-bind:class="task.status_class" v-bind:id="'task-status-' + task.nid">
      <td class="hosting-status">
        <span class="views-field-task-type">{{ task.task_type_name }}:</span> <a class="reference" v-bind:href="task.ref_url">{{ task.node_hosting_task_title }}</a>
      </td>
      <td>
        <time class="timeago" v-bind:datetime="task.timestamp">{{ task.timestamp_human }}</time>
      </td>
      <td>
        <time class="timeago executed" v-bind:datetime="task.timestamp_executed">{{ task.timestamp_executed_human }}</time>
      </td>
      <td>
        <span class="executed-time">
          {{ task.hosting_task_delta_human }}
        </span>
      </td>
      <td class="views-field views-field-nid hosting-actions">
        <a v-bind:href="task.task_url" class="hosting-button-enabled hosting-button-log hosting-button-dialog">{{ task.task_link_text }}</a>
      </td>
    </tr>
  </template>
  <noscript>
  <?php foreach ($rows as $row_count => $row): ?>
    <tr <?php if ($row_classes[$row_count]) { print 'class="' . implode(' ', $row_classes[$row_count]) .'"';  } ?>>
      <?php foreach ($row as $field => $content): ?>
        <td <?php if ($field_classes[$field][$row_count]) { print 'class="'. $field_classes[$field][$row_count] . '" '; } ?><?php print drupal_attributes($field_attributes[$field][$row_count]); ?>>
          <?php print $content; ?>
        </td>
      <?php endforeach; ?>
    </tr>
  <?php endforeach; ?>
  </noscript>
  </tbody>
</table>
