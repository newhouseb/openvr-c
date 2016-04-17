#include <stdio.h>
#include "openvr_c.h"

int main() {
  printf("Hello ben %d\n", VR_IsHmdPresent());

  EVRInitError error = VRInitError_None;
  VR_Init(&error, VRApplication_Scene);

  if (error != VRInitError_None) {
    printf("Failed to init %s\n", VR_GetVRInitErrorAsEnglishDescription(error));
  }

  IVRSystem *system = VRSystem();
  bool on_desktop = IVRSystem_IsDisplayOnDesktop(system);

  uint32_t w = 0;
  uint32_t h = 0;
  IVRSystem_GetRecommendedRenderTargetSize(system, &w, &h);

  printf("Initialized! %d %u %u\n", on_desktop, w, h);

  VR_Shutdown();

  printf("Goodbye!\n");
}
