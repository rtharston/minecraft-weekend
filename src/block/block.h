#ifndef BLOCK_H
#define BLOCK_H

#include "../util/util.h"
#include "../gfx/blockatlas.h"
#include "../world/blockmesh.h"
#include "../world/light.h"

// Forward declaration
struct World;

#define BLOCK_ID_LAST PINE_LEAVES
enum BlockId {
    AIR = 0,
    GRASS = 1,
    DIRT = 2,
    STONE = 3,
    SAND = 4,
    WATER = 5,
    GLASS = 6,
    LOG = 7,
    LEAVES = 8,
    ROSE = 9,
    BUTTERCUP = 10,
    COAL = 11,
    COPPER = 12,
    LAVA = 13,
    CLAY = 14,
    GRAVEL = 15,
    PLANKS = 16,
    TORCH = 17,
    COBBLESTONE = 18,
    SNOW = 19,
    PODZOL = 20,
    SHRUB = 21,
    TALLGRASS = 22,
    PINE_LOG = 23,
    PINE_LEAVES = 24
};

enum BlockFlags {
    // if true, this block is treated as it is transparent
    B_TRANSPARENT = 1 << 0,
    // if true, this block is treated like a liquid
    LIQUID = 1 << 1,
    // if true, then this block's aabb is determined by get_block_aabb
    SOLID = 1 << 2,
};

struct Block {
    enum BlockId id;

    // info about the block like transparent, liquid, and solid
    enum BlockFlags flags;

    // the mesh type of this block, see blockmesh.h
    enum BlockMeshType mesh_type;

    // gravity modifier for non-solid blocks
    f32 gravity_modifier;

    // drag for non-solid blocks
    f32 drag;

    // sliperiness for solid blocks
    f32 sliperiness;

    ivec2s (*get_texture_location)(struct World *world, ivec3s pos, enum Direction d);
    void (*get_mesh_information)(
        struct World *world, ivec3s pos, enum Direction d,
        vec3s *offset_out, vec3s *size_out,
        ivec2s *uv_offset_out, ivec2s *uv_size_out);

    // if not NULL, this is called to determine this block's textures
    void (*get_animation_frames)(ivec2s out[BLOCK_ATLAS_FRAMES]);

    // if not NULL, this block is treated as a light source
    Torchlight (*get_torchlight)(struct World *world, ivec3s pos);
};


void get_block_aabb(struct World *world, ivec3s pos, AABB dest);

#define MAX_BLOCK_ID INT16_MAX

extern struct Block BLOCK_DEFAULT;
extern struct Block BLOCKS[MAX_BLOCK_ID];

#define _BLOCK_DECL(_name)\
    extern void _name##_init();\
    _name##_init();

static inline void block_init() {
    _BLOCK_DECL(air);
    _BLOCK_DECL(grass);
    _BLOCK_DECL(dirt);
    _BLOCK_DECL(stone);
    _BLOCK_DECL(sand);
    _BLOCK_DECL(water);
    _BLOCK_DECL(glass);
    _BLOCK_DECL(log);
    _BLOCK_DECL(leaves);
    _BLOCK_DECL(rose);
    _BLOCK_DECL(buttercup);
    _BLOCK_DECL(coal);
    _BLOCK_DECL(copper);
    _BLOCK_DECL(lava);
    _BLOCK_DECL(clay);
    _BLOCK_DECL(gravel);
    _BLOCK_DECL(planks);
    _BLOCK_DECL(torch);
    _BLOCK_DECL(cobblestone);
    _BLOCK_DECL(snow);
    _BLOCK_DECL(podzol);
    _BLOCK_DECL(shrub);
    _BLOCK_DECL(tallgrass);
    _BLOCK_DECL(pine_log);
    _BLOCK_DECL(pine_leaves);
}

#endif