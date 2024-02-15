anariCommitParameters(device, device);
ANARIWorld varworld1 = anariNewWorld(device);
ANARIFrame varframe2 = anariNewFrame(device);
uint32_t size0[] = {640, 480};
anariSetParameter(device, varframe2, "size", ANARI_UINT32_VEC2, size0);
int32_t channel_color1 = ANARI_UFIXED8_VEC4;
anariSetParameter(device, varframe2, "channel.color", ANARI_DATA_TYPE, &channel_color1);
ANARIRenderer varrenderer3 = anariNewRenderer(device, "debug");
float background2[] = {1.0f, 1.0f, 1.0f, 1};
anariSetParameter(device, varrenderer3, "background", ANARI_FLOAT32_VEC4, background2);
anariCommitParameters(device, varrenderer3);
ANARICamera varcamera4 = anariNewCamera(device, "orthographic");
float aspect3 = 1.33333;
anariSetParameter(device, varcamera4, "aspect", ANARI_FLOAT32, &aspect3);
float position4[] = {0, -63.6113, -43.0982};
anariSetParameter(device, varcamera4, "position", ANARI_FLOAT32_VEC3, position4);
float direction5[] = {0, 0.827878, 0.560908};
anariSetParameter(device, varcamera4, "direction", ANARI_FLOAT32_VEC3, direction5);
float up6[] = {1, 0, 0};
anariSetParameter(device, varcamera4, "up", ANARI_FLOAT32_VEC3, up6);
float height7 = 94.4089;
anariSetParameter(device, varcamera4, "height", ANARI_FLOAT32, &height7);
anariCommitParameters(device, varcamera4);
ANARIArray1D vararray1d5 = anariNewArray1D(device, NULL, NULL, NULL, ANARI_FLOAT32_VEC3, 2);
void *mapping_vararray1d5 = anariMapArray(device, vararray1d5);
memcpy(mapping_vararray1d5, data(0, 24), 24);
anariUnmapArray(device, vararray1d5);
ANARIArray1D vararray1d6 = anariNewArray1D(device, NULL, NULL, NULL, ANARI_FLOAT32_VEC3, 2);
void *mapping_vararray1d6 = anariMapArray(device, vararray1d6);
memcpy(mapping_vararray1d6, data(24, 24), 24);
anariUnmapArray(device, vararray1d6);
anariRetain(device, vararray1d6);
anariRetain(device, vararray1d6);
anariRetain(device, vararray1d5);
anariRetain(device, vararray1d6);
anariRetain(device, vararray1d5);
ANARIGeometry vargeometry7 = anariNewGeometry(device, "cylinder");
anariSetParameter(device, vargeometry7, "vertex.position", ANARI_ARRAY1D, &vararray1d5);
anariUnsetParameter(device, vargeometry7, "primitive.radius");
float radius8 = 2;
anariSetParameter(device, vargeometry7, "radius", ANARI_FLOAT32, &radius8);
anariSetParameter(device, vargeometry7, "vertex.color", ANARI_ARRAY1D, &vararray1d6);
anariUnsetParameter(device, vargeometry7, "vertex.attribute0");
anariSetParameter(device, vargeometry7, "caps", ANARI_STRING, "none");
anariCommitParameters(device, vargeometry7);
ANARIMaterial varmaterial8 = anariNewMaterial(device, "matte");
anariSetParameter(device, varmaterial8, "color", ANARI_STRING, "color");
anariCommitParameters(device, varmaterial8);
anariRetain(device, varmaterial8);
ANARISurface varsurface9 = anariNewSurface(device);
anariSetParameter(device, varsurface9, "geometry", ANARI_GEOMETRY, &vargeometry7);
anariSetParameter(device, varsurface9, "material", ANARI_MATERIAL, &varmaterial8);
anariCommitParameters(device, varsurface9);
ANARIGroup vargroup10 = anariNewGroup(device);
const ANARISurface varsurface_local9[] = {varsurface9};
ANARIArray1D vararray1d11 = anariNewArray1D(device, varsurface_local9, NULL, NULL, ANARI_SURFACE, 1);
anariSetParameter(device, vargroup10, "surface", ANARI_ARRAY1D, &vararray1d11);
anariRelease(device, vararray1d11);
anariCommitParameters(device, vargroup10);
anariRelease(device, varsurface9);
ANARIInstance varinstance12 = anariNewInstance(device, "transform");
//[WARN ] anariSetParameter: Unknown parameter "group" on "varinstance12"
anariSetParameter(device, varinstance12, "group", ANARI_GROUP, &vargroup10);
uint32_t id10 = 0;
anariSetParameter(device, varinstance12, "id", ANARI_UINT32, &id10);
//[WARN ] anariSetParameter: Unknown parameter "transform" on "varinstance12"
float transform11[] = {1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1};
anariSetParameter(device, varinstance12, "transform", ANARI_FLOAT32_MAT4, transform11);
anariCommitParameters(device, varinstance12);
anariRetain(device, varinstance12);
anariRelease(device, varmaterial8);
anariRelease(device, vararray1d5);
anariRelease(device, vararray1d6);
anariRelease(device, vararray1d6);
ANARIArray1D vararray1d13 = anariNewArray1D(device, data(48, 96), deleter, deleterData, ANARI_FLOAT32_VEC3, 8);
anariRetain(device, vararray1d13);
ANARIArray1D vararray1d14 = anariNewArray1D(device, NULL, NULL, NULL, ANARI_FLOAT32_VEC3, 8);
void *mapping_vararray1d14 = anariMapArray(device, vararray1d14);
memcpy(mapping_vararray1d14, data(144, 96), 96);
anariUnmapArray(device, vararray1d14);
anariRetain(device, vararray1d14);
anariRelease(device, vararray1d14);
anariRelease(device, vararray1d13);
const ANARIInstance varinstance_local12[] = {varinstance12};
ANARIArray1D vararray1d15 = anariNewArray1D(device, varinstance_local12, NULL, NULL, ANARI_INSTANCE, 1);
float ambient_intensity = 1.f;
anariSetParameter(device, varrenderer3, "ambientIntensity", ANARI_FLOAT32, &ambient_intensity);
anariCommitParameters(device, varrenderer3);
anariSetParameter(device, varworld1, "instance", ANARI_ARRAY1D, &vararray1d15);
anariRelease(device, vararray1d15);
anariCommitParameters(device, varworld1);
anariSetParameter(device, varframe2, "renderer", ANARI_RENDERER, &varrenderer3);
anariSetParameter(device, varframe2, "camera", ANARI_CAMERA, &varcamera4);
anariSetParameter(device, varframe2, "world", ANARI_WORLD, &varworld1);
anariCommitParameters(device, varframe2);
anariRenderFrame(device, varframe2);
anariFrameReady(device, varframe2, ANARI_WAIT);
uint32_t width_local13;
uint32_t height_local13;
ANARIDataType type_local13;
const void *mapped_channel_color13 = anariMapFrame(device, varframe2, "channel.color", &width_local13, &height_local13, &type_local13);
// returned width = 640 height = 480 format = ANARI_UFIXED8_VEC4
image("channel.color", mapped_channel_color13, width_local13, height_local13, type_local13);
anariUnmapFrame(device, varframe2, "channel.color");
anariRelease(device, varcamera4);
anariRelease(device, vararray1d5);
//[WARN ] anariRelease: Releasing unused object (vararray1d14).
anariRelease(device, vararray1d14);
//[WARN ] anariRelease: Releasing unused object (vararray1d13).
anariRelease(device, vararray1d13);
anariRelease(device, varinstance12);
anariRelease(device, vargroup10);
anariRelease(device, varmaterial8);
anariRelease(device, vararray1d5);
anariRelease(device, vararray1d6);
anariRelease(device, vargeometry7);
anariRelease(device, vararray1d6);
anariRelease(device, varrenderer3);
anariRelease(device, varinstance12);
anariRelease(device, varworld1);
anariRelease(device, varframe2);
//[INFO ] used features:
//[INFO ]    ANARI_KHR_CAMERA_ORTHOGRAPHIC
//[INFO ]    ANARI_KHR_GEOMETRY_CYLINDER
//[INFO ]    ANARI_KHR_MATERIAL_MATTE
//[INFO ]    ANARI_KHR_RENDERER_BACKGROUND_COLOR
//[WARN ] anariReleaseDevice: Unused object (vararray1d13).
//[WARN ] anariReleaseDevice: Unused object (vararray1d14).
