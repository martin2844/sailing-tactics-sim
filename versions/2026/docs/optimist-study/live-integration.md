# Playable Optimist integration

The approved measured Optimist is now class 1 in both the starter preview and the 2026 live fleet. The Laser and Keelboat still use `NativeBoatMesh`; all eight compass images for each are byte-identical to the restored OG baseline. The 2002 and 2010 apps and numerical engine are unchanged.

## State mapping

`BoatModel` defines a common rendering contract. `OptimistBoatMesh` recovers heel from the original deck's transverse axis and trim from the unheeled tack-to-clew vector. The original sail's black fill controls penalty colour. The scene still owns world position, heading, interpolation and the pause-aware animation clock.

The measured 2.36 m hull is scaled uniformly to the original four-model-unit hull length (16 simulation units). It retains the reviewed width-to-length ratio. Its waterline is 0.13 m above the hull datum; heel rotates around that waterline. The original contact solver and contact envelopes are unchanged, so this is a visual replacement, not new hydrodynamics or a collision-model revision.

Boom rotation runs every displayed frame. Small cloth billow is sampled at 10 Hz, staggered across the fleet; the rig uses reusable buffers between those samples. Sail panels, insignia and battens rotate together. Fixed mast/tiller geometry and fixed sheet endpoints remain attached to the hull. The pause clock freezes flutter as well as boom movement.

The standard Chrome/WebGL 2 water material excludes the open hull's interior, using the same hull station table as the mesh. This avoids a water plane cutting through the cockpit floor. This material hook does not apply to the experimental WebGPU comparison renderer; that path still needs an equivalent node-material mask. Desktop Chrome on the normal game URL is the evaluated path; no mobile claim.

## Evaluation

- TypeScript and production build passed.
- `tools/optimist-study-qa.mjs`: standalone study geometry, framing, tack/crew and controls remain covered.
- `tools/optimist-live-eval.mjs`: ten live/study cloth comparisons, both tacks, trim, penalty, finite vertices/normals, paused geometry stability, headwind flutter and stable crew position when a released sail crosses the centreline. Maximum cloth coordinate error was approximately 0.00000012 m.
- Private engine fixtures confirmed distinct boom angles and mirrored heel/tack. Before/after whole-state and RNG boundaries were identical.
- Desktop Chrome, Radeon RX 7800 XT: 30 Optimists at selected 32× reached approximately 33× on the instantaneous pace measurement. The 300-sample browser animation callback trace had a 12.5 ms median and 25 ms p95, with four intervals over 50 ms. These are browser callback intervals, not a guarantee of 60 rendered frames per second or performance on other hardware. Headless Chrome selected software rendering and was unsuitable for this throughput measurement.
- Production smoke checks loaded and started Optimist, Laser and Keelboat fleets.
- Eight-angle captures plus live close-up and starter screenshots were visually inspected for sail shape, dry cockpit, rig, sailor and clipping.

Receipts and screenshots: `../../analysis/app/boat-redesign/optimist-integration/`, `optimist-live/`, `optimist-live-views/`, and `optimist-live-study-qa/`.
