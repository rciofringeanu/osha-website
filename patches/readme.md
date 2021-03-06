#Patches

When patching a contrib module, the following steps should be followed:
1. Copy the patch file in this folder: <module_name>/<patch_file>
2. Apply the patch to the module
3. Commit

List of patches (most recent first)

* workbench_moderation
  * Fix bug CW-438 when URL in original language is lost when adding a new translation
  * -workbench_moderation/workbench_moderation/cw_438_workbench_moderation_url_1_D7.patch.patch-
  * Bug report: https://www.drupal.org/node/1946392
  * Applied patch from here: https://www.drupal.org/files/et_language-1946392-1.patch

* features_extra
  * Fix tests error for nodequeue
  * features_extra-invalid-argument-foreach-2018515-1.patch
  * https://www.drupal.org/files/features_extra-invalid-argument-foreach-2018515-1.patch

* blockgroup
  * Allow feature revert
  * https://www.drupal.org/node/2189393
  * https://www.drupal.org/files/issues/blockgroup-7.x-1.x-features-revert-bug.diff

* blockgroup
  * Allow region theme hook
  * https://www.drupal.org/node/2043743
  * https://www.drupal.org/files/issues/blockgroup-region_template_suggestion-2043743-2.patch

* workbench_moderation
  * Added patch for node_export
  * https://www.drupal.org/node/2176841
  * https://www.drupal.org/files/issues/node_export-2176841-4.patch

* entity_translation
  * Added entity_translation in views (to be able to filter by language)
  * https://www.drupal.org/node/1330332
  * https://www.drupal.org/files/issues/entity_translation-filter_views-1330332-47.patch

* rules
  * added && if isset($data[$hook]) to avoid error when running update.sh (https://www.drupal.org/node/2161847)
  * https://www.drupal.org/files/issues/rules-fix-unsupported-operand-types-2161847-2.patch
* nodequeue
  * Fix undefined function apachesolr_mark_node (https://www.drupal.org/node/1425326)
  * https://www.drupal.org/files/nodequeue-apachesolr-fix.patch

* uuid_features
  * Add support for workbench moderation states. It sets published if exported revision published.
  * uuid_features/uuid_features-workbench-moderation-state-support.patch

* features
  * Add support for node UUID in menu import/export
  * features/features_menu_uuid_export.patchs

* menuimage
  * Modify menulink options to use image uri, not fid. Useful for features export/import
  * menuimage/menuimage_store_path_not_fid.patch

* workbench_moderation
  * Fix bug when insert/update node, current revision exclude form updating
  * workbench_moderation/workbench_moderation_bug_set_revision_state_0_of_current_revision.patch

* entity_collection
  * Fix bug when saving different entities with same eid (overwrites one another)
  * entity_collection/entity_collection-entities-with-same-eid.patch

* entity_collection
  * Fixed undefined variable
  * [https://www.drupal.org/node/2330513](https://www.drupal.org/files/issues/entity_collection_undefined_variable.patch)
  * entity_collection/entity_collection_undefined_variable.patch

* menu_block
  * Add hooks for editing, saving, deleting menu block. Useful for modules that want to extend the menu block form.
  * menu_block/menu_block_add_hooks_edit_save_delete_block.patch

* menuimage
  * Fix bug of redirect after menu save
  * https://www.drupal.org/node/2139233
  * menuimage/edit_item_alter_submit-page_not_found_if_multilingual_is_activated-2139233_0.patch


* entity_translation
  * Fix bug of incorrect language none for pathauto alias
  * https://www.drupal.org/node/1925848
  * entity_translation/entitytranslation-incorrect_pathauto_pattern-1925848-8.patch

* migrate (7.x-2.5)
  * Add support for FILE_EXISTS_RENAME option
  * migrate/migrate_file_rename_option.patch

* migrate (7.x-2.5)
  * Add support for file entity in file.inc destination plugin
  * patch created from code copied form 2.x-dev version of the module
  * migrate/migrate_file_plugin_file_entity_support.patch

* file_entity
  * Fix to let features export the display settings of the default file types
  * https://www.drupal.org/node/2192391#comment-8878719
  * file_entity/file_entity_remove_file_display-2192391-16.patch

* media
  * Fix to let features export the display settings of the default file types
  * https://www.drupal.org/node/2104193#comment-8878701
  * media/media_remove_file_display_alter-2104193-76.patch

* media
  * Restore Edit button in Media Browser Widget
  * https://www.drupal.org/node/2192981#comment-9004143
  * media/media-restore-edit-button-2192981-13.patch

* pdf_to_image
  * Check for empty values to prevent errors (occured in migrate)
  * pdf_to_image_check_empty_values.patch

* pdf_to_image
  * Skip it if entity saved trough cli (used for migrate)
  * pdf_to_imagefield/pdf_to_image_skip_if_cli.patch

* pdf_to_image
  * Fix for thumbnails of translated files
  * pdf_to_imagefield/pdf_to_imagefield_7-3-3-fix-for-multilingual.patch

* pdf_to_image
  * Allows files of other types than .pdf to be uploaded when field is using pdf_to_image widget
  * This patch is needed by doc_to_imagefield module
  * pdf_to_imagefield/pdf_to_imagefield-allow_non_pdf_file.patch


Patch documentation should be in the following format:

* module name
  * brief description
  * issue link (if exists)
  * patch file location
---