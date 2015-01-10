Kore Components
===============
* Field
* Field_Widget
* Field_Formatter
* Field_Form
* Field_Display

Image Styles
============
* a 1140px
* b 930px
* c 768px
* d 555px
* e 360px
* f 263px
* g 165px
* h 68px

Theme
=====
<dl>
  <dt>html_list</dt>
    <dd>Standard HTML list tags.</dd>
  <dt>timeago</dt>
    <dd>Use moment.js to transfer datetime to relative 'time ago' format.</dd>
  <dt>dropdown</dt>
    <dd></dd>
  <dt>kore_image</dt>
    <dd></dd>
</dl>

Panels Layouts
==============
* chaos 1
* chronos 1/2, 1/2
* gaia 3/4, 1/4
    - gaia_a
    - gaia_b
* phanes 5/6, 1/6
* poseidon 1/3, 1/3, 1/3
* zeus 2/3, 1/3

Views Style Plugins
===================
* blockgrid

Form
====
* #submit
    - kore_form_submit_redirect(), use 'redirect_kore' to redirect after form being submitted.
    - kore_form_submit_redirect_up(), just redirect to upper directory.

Kitem
=====
Plugins for theme_registry kitem.
Support subtypes.
    $vars = array(
      'type' => '',
      'item' => $item,
      'settings' => $settings,
    );
Usage: kitem_theme($vars);
