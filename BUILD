package(default_visibility = ["//visibility:public"])

cc_library(
    name = "heroes_h",
    hdrs = ["fheroes2/heroes/heroes.h"],
    strip_include_prefix = "fheroes2/heroes",
    deps = [
        ":pairs_h",
        ":army",
    ],
)

cc_library(
    name = "heroes_src",
    srcs = [
        "fheroes2/heroes/heroes_recruits.cpp",
        "fheroes2/heroes/heroes.cpp",
        "fheroes2/heroes/skill.cpp",
        "fheroes2/heroes/route.cpp",
        "fheroes2/heroes/direction.cpp",
        "fheroes2/heroes/heroes_base.cpp",
    ],
    deps = [
        ":heroes_h",
        ":agg",
        ":ai",
        ":battle",
        ":army",
        ":castle",
        ":game",
        ":kingdom",
        ":world",
    ],
)

cc_library(
    name = "heroes",
    hdrs = [
        "fheroes2/heroes/route.h",
        "fheroes2/heroes/direction.h",
        "fheroes2/heroes/skill.h",
        "fheroes2/heroes/skill_static.h",
        "fheroes2/heroes/heroes_recruits.h",
        "fheroes2/heroes/heroes_base.h",
    ],
    strip_include_prefix = "fheroes2/heroes",
    deps = [
        ":spell",
    ],
)

cc_library(
    name = "engine",
    srcs = [
        "engine/translations.cpp",
        "engine/screen.cpp",
        "engine/image.cpp",
        "engine/rand.cpp",
        "engine/serialize.cpp",
        "engine/logging.cpp",
        "engine/agg_file.cpp",
        "engine/localevent.cpp",
        "engine/timing.cpp",
        "engine/system.cpp",
        "engine/audio.cpp",
    ],
    hdrs = [
        "engine/engine.h",
        "engine/rand.h",
        "engine/timer.h",
        "engine/zzlib.h",
        "engine/screen.h",
        "engine/serialize.h",
        "engine/endian_h2.h",
        "engine/translations.h",
        "engine/image.h",
        "engine/types.h",
        "engine/tools.h",
        "engine/math_base.h",
        "engine/pathfinding.h",
        "engine/localevent.h",
        "engine/timing.h",
        "engine/logging.h",
        "engine/dir.h",
        "engine/palette_h2.h",
        "engine/pal.h",
        "engine/audio.h",
        "engine/tinyconfig.h",
        "engine/system.h",
        "engine/agg_file.h",
        "engine/image_tool.h",
    ],
    strip_include_prefix = "engine",
    deps = [
        ":heroes",
    ],
)

cc_library(
    name = "system",
    hdrs = [
        "fheroes2/system/gamedefs.h",
        "fheroes2/system/players.h",
        "fheroes2/system/bitmodes.h",
        "fheroes2/system/settings.h",
        "fheroes2/system/version.h",
        "fheroes2/system/save_format_version.h",
    ],
    strip_include_prefix = "fheroes2/system",
    deps = [
        ":color_h",
    ],
)

cc_library(
    name = "agg",
    hdrs = [
        "fheroes2/agg/m82.h",
        "fheroes2/agg/agg.h",
        "fheroes2/agg/til.h",
        "fheroes2/agg/xmi.h",
        "fheroes2/agg/mus.h",
        "fheroes2/agg/bin_info.h",
        "fheroes2/agg/icn.h",
        "fheroes2/agg/agg_image.h",
    ],
    strip_include_prefix = "fheroes2/agg",
)

cc_library(
    name = "game_interface_h",
    hdrs = ["fheroes2/game/game_interface.h"],
    strip_include_prefix = "fheroes2/game",
    deps = [
        ":interface_radar_h",
    ],
)

cc_library(
    name = "game",
    hdrs = [
        "fheroes2/game/difficulty.h",
        "fheroes2/game/game_static.h",
        "fheroes2/game/game.h",
        "fheroes2/game/game_video_type.h",
        "fheroes2/game/game_over.h",
        "fheroes2/game/game_credits.h",
        "fheroes2/game/game_delays.h",
        "fheroes2/game/game_io.h",
    ],
    strip_include_prefix = "fheroes2/game",
    deps = [
        ":agg",
        ":gui",
        ":game_mode_h",
    ],
)

cc_library(
    name = "castle_src",
    srcs = ["fheroes2/castle/castle.cpp"],
    hdrs = ["fheroes2/castle/castle.h"],
    deps = [
        ":agg",
        ":ai",
        ":battle",
        ":army",
        ":castle",
        ":game",
        ":kingdom",
        ":world",
    ],
)

cc_library(
    name = "castle",
    hdrs = [
        "fheroes2/castle/castle.h",
        "fheroes2/castle/castle_heroes.h",
        "fheroes2/castle/captain.h",
        "fheroes2/castle/mageguild.h",
        "fheroes2/castle/castle_building_info.h",
    ],
    strip_include_prefix = "fheroes2/castle",
    deps = [
        ":gui",
        ":army",
        ":heroes_h",
    ],
)

cc_library(
    name = "battle",
    hdrs = [
        "fheroes2/battle/battle_arena.h",
        "fheroes2/battle/battle.h",
        "fheroes2/battle/battle_board.h",
        "fheroes2/battle/battle_cell.h",
        "fheroes2/battle/battle_army.h",
        "fheroes2/battle/battle_command.h",
        "fheroes2/battle/battle_tower.h",
        "fheroes2/battle/battle_troop.h",
        "fheroes2/battle/battle_grave.h",
        "fheroes2/battle/battle_pathfinding.h",
        "fheroes2/battle/battle_animation.h",
        "fheroes2/battle/battle_bridge.h",
        "fheroes2/battle/battle_catapult.h",
        "fheroes2/battle/battle_interface.h",
    ],
    strip_include_prefix = "fheroes2/battle",
    deps = [
        ":agg",
        ":spell",
    ],
)

cc_library(
    name = "game_mode_h",
    hdrs = ["fheroes2/game/game_mode.h"],
    strip_include_prefix = "fheroes2/game",
)

cc_library(
    name = "spell",
    hdrs = [
        "fheroes2/spell/spell.h",
        "fheroes2/spell/spell_book.h",
        "fheroes2/spell/spell_storage.h",
    ],
    strip_include_prefix = "fheroes2/spell",
)

cc_library(
    name = "dialog_selectitems_h",
    hdrs = ["fheroes2/dialog/dialog_selectitems.h"],
    deps = [
        ":resource",
        ":heroes_h",
        ":army",
        ":gui"
    ],
    strip_include_prefix = "fheroes2/dialog",
)

cc_library(
    name = "dialog",
    hdrs = [
        "fheroes2/dialog/dialog.h",
    ],
    strip_include_prefix = "fheroes2/dialog",
    deps = [
        ":game_mode_h",
        ":system",
    ],
)

cc_library(
    name = "interface_radar_h",
    hdrs = ["fheroes2/gui/interface_radar.h"],
    deps = [
        ":kingdom",
    ],
    strip_include_prefix = "fheroes2/gui",
)

cc_library(
    name = "gui",
    hdrs = [
        "fheroes2/gui/interface_itemsbar.h",
        "fheroes2/gui/interface_buttons.h",
        "fheroes2/gui/ui_tool.h",
        "fheroes2/gui/ui_text.h",
        "fheroes2/gui/interface_border.h",
        "fheroes2/gui/ui_base.h",
        "fheroes2/gui/ui_button.h",
        "fheroes2/gui/ui_window.h",
        "fheroes2/gui/text.h",
        "fheroes2/gui/cursor.h",
        "fheroes2/gui/statusbar.h",
        "fheroes2/gui/interface_cpanel.h",
        "fheroes2/gui/interface_gamearea.h",
        "fheroes2/gui/interface_icons.h",
        "fheroes2/gui/interface_list.h",
        "fheroes2/gui/ui_scrollbar.h",
        "fheroes2/gui/interface_status.h",
    ],
    strip_include_prefix = "fheroes2/gui",
    deps = [
        ":dialog",
        ":engine",
    ]
)

cc_library(
    name = "pairs_h",    
    hdrs = [
        "fheroes2/maps/pairs.h",
    ],
    strip_include_prefix = "fheroes2/maps",
    deps = [":resource"],
)

cc_library(
    name = "maps_tiles_h",
    hdrs = ["fheroes2/maps/maps_tiles.h"],
    deps = [
        ":army",
    ],
    strip_include_prefix = "fheroes2/maps",
)

cc_library(
    name = "maps",
    hdrs = [
        "fheroes2/maps/mp2.h",
        "fheroes2/maps/position.h",
        "fheroes2/maps/visit.h",
        "fheroes2/maps/maps.h",
        "fheroes2/maps/maps_fileinfo.h",
        "fheroes2/maps/ground.h",
        "fheroes2/maps/maps_actions.h",
        "fheroes2/maps/maps_objects.h",
    ],
    strip_include_prefix = "fheroes2/maps",
    deps = [
        ":color_h",
        ":engine",
    ],
)

cc_library(
    name = "payment_h",
    hdrs = ["fheroes2/kingdom/payment.h"],
    strip_include_prefix = "fheroes2/kingdom",
)

cc_library(
    name = "color_h",
    hdrs = ["fheroes2/kingdom/color.h",],
    strip_include_prefix = "fheroes2/kingdom",
)

cc_library(
    name = "kingdom",
    hdrs = [
        "fheroes2/kingdom/kingdom.h",
        "fheroes2/kingdom/puzzle.h",
        "fheroes2/kingdom/race.h",
        "fheroes2/kingdom/profit.h",
        "fheroes2/kingdom/speed.h",
        "fheroes2/kingdom/week.h",
        "fheroes2/kingdom/luck.h",
        "fheroes2/kingdom/morale.h",
        "fheroes2/kingdom/view_world.h",
    ],
    strip_include_prefix = "fheroes2/kingdom",
    deps = [
        ":game",
        ":castle",
    ],
)

cc_library(
    name = "resource",
    hdrs = [
        "fheroes2/resource/resource.h",
        "fheroes2/resource/artifact.h",
        "fheroes2/resource/artifact_ultimate.h",
    ],
    strip_include_prefix = "fheroes2/resource",
    deps = [
        ":gui",
        ":engine",
        ":maps",
    ],
)

cc_library(
    name = "monster",
    hdrs = [
        "fheroes2/monster/monster.h",
        "fheroes2/monster/monster_anim.h",
        "fheroes2/monster/monster_info.h",
    ],
    strip_include_prefix = "fheroes2/monster",
    deps = [
        ":payment_h",
        ":resource",
        ":battle",
    ],
)

cc_library(
    name = "campaign",
    hdrs = [
        "fheroes2/campaign/campaign_data.h",
        "fheroes2/campaign/campaign_scenariodata.h",
        "fheroes2/campaign/campaign_savedata.h",
    ],
    strip_include_prefix = "fheroes2/campaign",
    deps = [
        ":game",
    ],
)


cc_library(
    name = "army",
    hdrs = [
        "fheroes2/army/army.h",
        "fheroes2/army/army_troop.h",
    ],
    strip_include_prefix = "fheroes2/army",
    deps = [
        ":system",
        ":monster",
    ],
)

cc_library(
    name = "army_src",
    srcs = [
        "fheroes2/army/army.cpp",
        "fheroes2/army/army_troop.cpp"
    ],
    deps = [
        ":army",
        ":agg",
        ":campaign",
        ":castle",
        ":world",
    ],
)

cc_library(
    name = "monster_src",
    srcs = [
        "fheroes2/monster/monster.cpp",
        "fheroes2/monster/monster_info.cpp",
    ],
    deps = [
        ":monster",
        ":castle",
        ":game",
        "kingdom",
    ],
)

cc_library(
    name = "world",
    hdrs = [
        "fheroes2/world/world.h",
        "fheroes2/world/world_pathfinding.h",
        "fheroes2/world/world_regions.h",
    ],
    strip_include_prefix = "fheroes2/world",
    deps = [
        ":army",
        ":maps",
        ":kingdom",
        ":maps_tiles_h",
    ],
)

cc_library(
    name = "ai",
    hdrs = [
        "fheroes2/ai/ai.h",
    ],
    strip_include_prefix = "fheroes2/ai",
    deps = [
        ":engine",
        ":system",
    ],
)

cc_library(
    name = "ai_normal",
    hdrs = [
        "fheroes2/ai/normal/ai_normal.h",
    ],
    deps = [
        ":ai",
        ":world",
    ],
    strip_include_prefix = "fheroes2/ai",
)

cc_library(
    name = "world_src",
    srcs = [
        "fheroes2/world/world.cpp",
        "fheroes2/world/world_pathfinding.cpp",
    ],
    deps = [
        ":world",
        ":ai",
        ":campaign",
        ":castle",
    ],
)

cc_library(
    name = "game_src",
    srcs = [
        "fheroes2/game/game_hotkeys.cpp",
        "fheroes2/game/game_static.cpp",
        "fheroes2/game/game.cpp",
    ],
    deps = [
        ":game_interface_h",
        ":maps_tiles_h",
        ":world",
        ":game",
        ":maps",
        ":engine",
        ":kingdom",
        ":resource",
        ":system",
    ],
)

cc_library(
    name = "resource_src",
    hdrs = ["fheroes2/resource/resource.h"],
    srcs = ["fheroes2/resource/resource.cpp"],
    deps = [
        ":engine",
        ":agg",
        ":pairs_h",
    ],
)

cc_library(
    name = "puzzle_src",
    hdrs = ["fheroes2/kingdom/puzzle.h"],
    srcs = ["fheroes2/kingdom/puzzle.cpp"],
    deps = [
        ":agg",
        ":gui",
        ":engine",
        ":game",
        ":maps",
        ":game_interface_h",
        ":world",
    ],
)

cc_library(
    name = "artifact_ultimate_cpp",
    hdrs = ["fheroes2/resource/artifact_ultimate.h"],
    srcs = ["fheroes2/resource/artifact_ultimate.cpp"],
    deps = [
        ":resource",
        ":game",
    ],
)

cc_library(
    name = "artifact_cpp",
    hdrs = ["fheroes2/resource/artifact.h"],
    srcs = ["fheroes2/resource/artifact.cpp"],
    deps = [
        ":agg",
        ":gui",
        ":engine",
        ":maps",
        ":dialog_selectitems_h",
    ],
)

cc_library(
    name = "ai_normal_src",
    srcs = [
        "fheroes2/ai/normal/ai_normal.cpp",
        "fheroes2/ai/normal/ai_normal_battle.cpp",
        "fheroes2/ai/normal/ai_normal_castle.cpp",
        "fheroes2/ai/normal/ai_normal_hero.cpp",
        "fheroes2/ai/normal/ai_normal_kingdom.cpp",
        "fheroes2/ai/normal/ai_normal_spell.cpp",
    ],
    deps = [
        ":ai_normal",
        ":battle",
        ":game_interface_h",
        ":maps_tiles_h",
    ],
)

cc_library(
    name = "ai_src",
    srcs = [
        "fheroes2/ai/ai_base.cpp",
        "fheroes2/ai/ai_common.cpp",
    ],
    deps = [
        ":agg",
        ":ai",
        ":battle",
        ":army",
        ":game_interface_h",
        ":ai_normal",
    ],
)

cc_library(
    name = "kingdom_src",
    srcs = [
        "fheroes2/kingdom/week.cpp",
        "fheroes2/kingdom/kingdom.cpp",
        "fheroes2/kingdom/color.cpp",
        "fheroes2/kingdom/morale.cpp",
    ],
    deps = [
        ":kingdom",
        ":ai",
        ":battle",
        ":army",
        ":campaign",
        ":game",
        ":world",
        ":game_interface_h",
        ":monster",
    ],
)

cc_library(
    name = "battle_src",
    srcs = [
        "fheroes2/battle/battle_arena.cpp",
        "fheroes2/battle/battle_grave.cpp",
        "fheroes2/battle/battle_main.cpp",
        "fheroes2/battle/battle_troop.cpp",
        "fheroes2/battle/battle_animation.cpp",
        "fheroes2/battle/battle_interface.cpp",
        "fheroes2/battle/battle_board.cpp",
        "fheroes2/battle/battle_cell.cpp",
        "fheroes2/battle/battle_army.cpp",
        "fheroes2/battle/battle_pathfinding.cpp",
        "fheroes2/battle/battle_command.cpp",
        "fheroes2/battle/battle_action.cpp",
    ],
    deps = [
        ":ai",
        ":army",
        ":battle",
        ":castle",
        ":kingdom",
        ":world",
    ],
)

cc_library(
    name = "spell_src",
    srcs = [
        "fheroes2/spell/spell_storage.cpp",
        "fheroes2/spell/spell.cpp",
    ],
    deps = [
        ":spell",
        ":resource",
        ":payment_h",
        ":kingdom",
    ],
)

cc_library(
    name = "system_src",
    srcs = [
        "fheroes2/system/players.cpp",
        "fheroes2/system/settings.cpp",
        "fheroes2/system/bitmodes.cpp",
    ],
    deps = [
        ":game",
        ":maps",
        ":engine",
        ":ai_normal",
    ],
)

cc_library(
    name = "maps_src",
    srcs = [
        "fheroes2/maps/visit.cpp",
        "fheroes2/maps/maps_fileinfo.cpp",
        "fheroes2/maps/maps_tiles.cpp",
        "fheroes2/maps/maps.cpp",
        "fheroes2/maps/position.cpp",
    ],
    deps = [
        ":resource",
        ":game",
        ":maps_tiles_h",
        ":kingdom",
        ":objects",
        ":world",
        ":ai",
        ":maps",
    ],
)

cc_library(
    name = "dialog_src",
    srcs = ["fheroes2/dialog/dialog_frameborder.cpp"],
    deps = [
        ":agg",
        ":dialog",
        ":engine",
        ":maps",
    ],
)


cc_library(
    name = "gui_src",
    srcs = [
        "fheroes2/gui/text.cpp",
        "fheroes2/gui/cursor.cpp",
        "fheroes2/gui/ui_tool.cpp",
        "fheroes2/gui/ui_button.cpp",
        "fheroes2/gui/ui_base.cpp",
        "fheroes2/gui/ui_scrollbar.cpp",
        "fheroes2/gui/ui_window.cpp",
    ],
    deps = [
        ":gui",
        ":agg",
        ":maps",
        ":game",
    ],
)

cc_library(
    name = "h2d",
    hdrs = ["fheroes2/h2d/h2d.h"],
    strip_include_prefix = "fheroes2/h2d",
)

cc_library(
    name = "image",
    hdrs = ["fheroes2/image/embedded_image.h"],
    strip_include_prefix = "fheroes2/image",
)

cc_library(
    name = "objects",
    hdrs = [
        "fheroes2/objects/mounts.h",
        "fheroes2/objects/objcrck.h",
        "fheroes2/objects/objdirt.h",
        "fheroes2/objects/objdsrt.h",
        "fheroes2/objects/objgras.h",
        "fheroes2/objects/objlava.h",
        "fheroes2/objects/objsnow.h",
        "fheroes2/objects/objmult.h",
        "fheroes2/objects/objswmp.h",
        "fheroes2/objects/objtown.h",
        "fheroes2/objects/objwatr.h",
        "fheroes2/objects/objxloc.h",
        "fheroes2/objects/trees.h",
    ],
    strip_include_prefix = "fheroes2/objects",
)

cc_library(
    name = "agg_src",
    srcs = [
        "fheroes2/agg/agg_image.cpp",
        "fheroes2/agg/icn.cpp",
        "fheroes2/agg/agg.cpp",
        "fheroes2/agg/bin_info.cpp",
    ],
    deps = [
        ":agg",
        ":engine",
        ":h2d",
        ":gui",
        ":heroes_h",
        ":kingdom",
        ":image",
    ],
)

cc_binary(
    name = "main",
    srcs = [
        "main.cpp",
    ],
    deps = [
        ":engine",
        ":resource_src",
        ":puzzle_src",
        ":artifact_ultimate_cpp",
        ":artifact_cpp",

        ":dialog_src",
        ":world_src",
        ":game_src",
        ":army_src",
        ":kingdom_src",
        ":castle_src",
        ":gui_src",
        ":ai_src",
        ":monster_src",
        ":heroes_src",
        ":ai_normal_src",
        ":battle_src",
        ":maps_src",
        ":spell_src",
        ":system_src",
        ":agg_src",
        "//common:Thread",
        "//common:ErrnoCheck",
    ],
    linkopts = [
        "-lSDL2",
    ],
)
