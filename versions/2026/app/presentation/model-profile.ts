/** Studio projection used to lift the preserved boat faces into3D. Width is
 * the audited Keelboat's canonical near-view calibration (the former default
 * first packet). It is independent of race visibility, camera and display size.
 * Packet normalization retains native hull, rig, crew and articulated boom data.
 */
export const studioRigWidth=0.3684507552870091;
/** The OG painter changes geometry/detail at fast numerical presets. Model
 * extraction always uses the audited detailed profile on its private image. */
export const studioDrawingSpeed=6;
export const studioDrawingDivisor=384;
