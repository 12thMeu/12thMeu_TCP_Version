#include "..\config_macros.hpp"

#define SCORPION_TEXTURESET \
hiddenSelectionsTextures[] = {                \
  QP(scorpion\default\hull_co.paa),             \
  QP(scorpion\default\turret_co.paa),           \
  QP(scorpion\default\track_front_co.paa),      \
  QP(scorpion\default\track_rear_co.paa),      \
  QP(scorpion\default\commander_co.paa),      \
  QP(scorpion\default\ext_co.paa),            \
  QP(scorpion\default\ext2_co.paa),           \
  QP(scorpion\default\track_int_co.paa),      \
}; \
class TextureSources { \
  class twelfth_scorpion_tex_default { \
    author="Wolfe"; \
    displayName="Default"; \
    textures[]= { \
      QP(scorpion\default\hull_co.paa),             \
      QP(scorpion\default\turret_co.paa),           \
      QP(scorpion\default\track_front_co.paa),      \
      QP(scorpion\default\track_rear_co.paa),      \
      QP(scorpion\default\commander_co.paa),      \
      QP(scorpion\default\ext_co.paa),            \
      QP(scorpion\default\ext2_co.paa),           \
      QP(scorpion\default\track_int_co.paa),      \
    }; \
  }; \
  class twelfth_scorpion_tex_brown {    \
    author = "Wolfe"; \
    displayName = "Brown"; \
    textures[] = {  \
      QP(scorpion\brown\hull_co.paa),             \
      QP(scorpion\brown\turret_co.paa),           \
      QP(scorpion\brown\track_front_co.paa),      \
      QP(scorpion\brown\track_rear_co.paa),      \
      QP(scorpion\brown\commander_co.paa),      \
      QP(scorpion\brown\ext_co.paa),            \
      QP(scorpion\brown\ext2_co.paa),           \
      QP(scorpion\brown\track_int_co.paa),      \
    };  \
  };  \
};