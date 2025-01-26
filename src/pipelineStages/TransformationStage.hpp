#include "../entities/TransformationEntity.hpp"
#include "../globals/GLOBALS.hpp"

class TransformationStage{
    public: static void run() {
        TransformationEntity::rotate(GLOBAL_THETA);
    }
};