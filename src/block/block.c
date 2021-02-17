#include "block.h"
#include "../gfx/blockatlas.h"

static ivec2s get_texture_location(struct World *world, ivec3s pos, enum Direction d) {
    assert(false);
    return GLMS_IVEC2_ZERO;
}

static void get_aabb(struct World *world, ivec3s pos, AABB dest) {
    dest[0] = IVEC3S2V(pos);
    dest[1] = (vec3s) {{ pos.x + 1.0f, pos.y + 1.0f, pos.z + 1.0f }};
}

static void get_mesh_information(
    struct World *world, ivec3s pos, enum Direction d,
    vec3s *offset_out, vec3s *size_out,
    ivec2s *uv_offset_out, ivec2s *uv_size_out) {
    assert(false);
}

// declared in block.h
struct Block BLOCKS[MAX_BLOCK_ID];

// Contains all default behavior for a block
struct Block BLOCK_DEFAULT = {
    .id = -1,
    .flags = SOLID,
    .gravity_modifier = 1.0f,
    .drag = 1.0f,
    .sliperiness = 1.0f,
    .mesh_type = BLOCKMESH_DEFAULT,
    .get_texture_location = get_texture_location,
    .get_animation_frames = NULL,
    .get_torchlight = NULL,
    .get_aabb = get_aabb,
    .get_mesh_information = get_mesh_information
};