// 0x0E000958
const GeoLayout wf_geo_15[] = {
   GEO_CULLING_RADIUS(2000),
   GEO_OPEN_NODE(),
      GEO_RENDER_RANGE(-2000, 8000),
      GEO_OPEN_NODE(),
         GEO_DISPLAY_LIST(LAYER_OPAQUE, mountain_15_dl_mesh),
         GEO_DISPLAY_LIST(LAYER_TRANSPARENT_DECAL, mountain_15_shadow_dl_mesh),
      GEO_CLOSE_NODE(),
      GEO_RENDER_RANGE(8000, 20000),
      GEO_OPEN_NODE(),
         GEO_DISPLAY_LIST(LAYER_OPAQUE, mountain_15_lod_dl_mesh),
      GEO_CLOSE_NODE(),
   GEO_CLOSE_NODE(),
   GEO_END(),
};
