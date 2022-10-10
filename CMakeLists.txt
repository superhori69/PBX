cmake_minimum_required(VERSION 3.0)
project(PinballRemasterX)

set(CMAKE_CXX_STANDARD 11)


set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_LIST_DIR}/bin)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/CMakeModules")

# On Windows, set paths to SDL-devel packages here
if(WIN32)
   list(APPEND SDL2_PATH "${CMAKE_CURRENT_LIST_DIR}/Lib/SDL2")
   list(APPEND SDL2_MIXER_PATH "${CMAKE_CURRENT_LIST_DIR}/Lib/SDL2_mixer")
   list(APPEND GAME_DATA_FILES "${CMAKE_CURRENT_LIST_DIR}/GameData")
   list(APPEND GAME_DATA_SOUNDS "${CMAKE_CURRENT_LIST_DIR}/GameData/SOUND/")
endif()

# Link mingw libs static
if(MINGW)
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -static")
endif()

# SDL2main is not needed
set(SDL2_BUILDING_LIBRARY ON)

find_package(SDL2 REQUIRED)
FIND_PACKAGE(SDL2_mixer REQUIRED)

include_directories(${SDL2_INCLUDE_DIR} ${SDL2_MIXER_INCLUDE_DIR})
get_property(dirs DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY INCLUDE_DIRECTORIES)
foreach(dir ${dirs})
  message(STATUS "Include dir='${dir}'")
endforeach()

set(SOURCE_FILES
        PinballRemasterX/control.cpp
        PinballRemasterX/control.h
        PinballRemasterX/EmbeddedData.cpp
        PinballRemasterX/EmbeddedData.h
        PinballRemasterX/font_selection.cpp
        PinballRemasterX/font_selection.h
        PinballRemasterX/fullscrn.cpp
        PinballRemasterX/fullscrn.h
        PinballRemasterX/gdrv.cpp
        PinballRemasterX/gdrv.h
        PinballRemasterX/GroupData.cpp
        PinballRemasterX/GroupData.h
        PinballRemasterX/high_score.cpp
        PinballRemasterX/high_score.h
        PinballRemasterX/loader.cpp
        PinballRemasterX/loader.h
        PinballRemasterX/maths.cpp
        PinballRemasterX/maths.h
        PinballRemasterX/midi.cpp
        PinballRemasterX/midi.h
        PinballRemasterX/nudge.cpp
        PinballRemasterX/nudge.h
        PinballRemasterX/options.cpp
        PinballRemasterX/options.h
        PinballRemasterX/partman.cpp
        PinballRemasterX/partman.h
        PinballRemasterX/pb.cpp
        PinballRemasterX/pb.h
        PinballRemasterX/pch.h
        PinballRemasterX/proj.cpp
        PinballRemasterX/proj.h
        PinballRemasterX/render.cpp
        PinballRemasterX/render.h
        PinballRemasterX/score.cpp
        PinballRemasterX/score.h
        PinballRemasterX/Sound.cpp
        PinballRemasterX/Sound.h
        PinballRemasterX/PinballRemasterX.cpp
        PinballRemasterX/TBall.cpp
        PinballRemasterX/TBall.h
        PinballRemasterX/TBlocker.cpp
        PinballRemasterX/TBlocker.h
        PinballRemasterX/TBumper.cpp
        PinballRemasterX/TBumper.h
        PinballRemasterX/TCircle.cpp
        PinballRemasterX/TCircle.h
        PinballRemasterX/TCollisionComponent.cpp
        PinballRemasterX/TCollisionComponent.h
        PinballRemasterX/TComponentGroup.cpp
        PinballRemasterX/TComponentGroup.h
        PinballRemasterX/TDemo.cpp
        PinballRemasterX/TDemo.h
        PinballRemasterX/TDrain.cpp
        PinballRemasterX/TDrain.h
        PinballRemasterX/TEdgeBox.h
        PinballRemasterX/TEdgeManager.cpp
        PinballRemasterX/TEdgeManager.h
        PinballRemasterX/TEdgeSegment.cpp
        PinballRemasterX/TEdgeSegment.h
        PinballRemasterX/TFlagSpinner.cpp
        PinballRemasterX/TFlagSpinner.h
        PinballRemasterX/TFlipper.cpp
        PinballRemasterX/TFlipper.h
        PinballRemasterX/TFlipperEdge.cpp
        PinballRemasterX/TFlipperEdge.h
        PinballRemasterX/TGate.cpp
        PinballRemasterX/TGate.h
        PinballRemasterX/THole.cpp
        PinballRemasterX/THole.h
        PinballRemasterX/timer.cpp
        PinballRemasterX/timer.h
        PinballRemasterX/TKickback.cpp
        PinballRemasterX/TKickback.h
        PinballRemasterX/TKickout.cpp
        PinballRemasterX/TKickout.h
        PinballRemasterX/TLight.cpp
        PinballRemasterX/TLight.h
        PinballRemasterX/TLightBargraph.cpp
        PinballRemasterX/TLightBargraph.h
        PinballRemasterX/TLightGroup.cpp
        PinballRemasterX/TLightGroup.h
        PinballRemasterX/TLightRollover.cpp
        PinballRemasterX/TLightRollover.h
        PinballRemasterX/TLine.cpp
        PinballRemasterX/TLine.h
        PinballRemasterX/TOneway.cpp
        PinballRemasterX/TOneway.h
        PinballRemasterX/TPinballComponent.cpp
        PinballRemasterX/TPinballComponent.h
        PinballRemasterX/TPinballTable.cpp
        PinballRemasterX/TPinballTable.h
        PinballRemasterX/TPlunger.cpp
        PinballRemasterX/TPlunger.h
        PinballRemasterX/TPopupTarget.cpp
        PinballRemasterX/TPopupTarget.h
        PinballRemasterX/TRamp.cpp
        PinballRemasterX/TRamp.h
        PinballRemasterX/translations.cpp
        PinballRemasterX/translations.h
        PinballRemasterX/TRollover.cpp
        PinballRemasterX/TRollover.h
        PinballRemasterX/TSink.cpp
        PinballRemasterX/TSink.h
        PinballRemasterX/TSoloTarget.cpp
        PinballRemasterX/TSoloTarget.h
        PinballRemasterX/TSound.cpp
        PinballRemasterX/TSound.h
        PinballRemasterX/TTableLayer.cpp
        PinballRemasterX/TTableLayer.h
        PinballRemasterX/TTextBox.cpp
        PinballRemasterX/TTextBox.h
        PinballRemasterX/TTextBoxMessage.cpp
        PinballRemasterX/TTextBoxMessage.h
        PinballRemasterX/TTimer.cpp
        PinballRemasterX/TTimer.h
        PinballRemasterX/TTripwire.cpp
        PinballRemasterX/TTripwire.h
        PinballRemasterX/TWall.cpp
        PinballRemasterX/TWall.h
        PinballRemasterX/winmain.cpp
        PinballRemasterX/winmain.h
        PinballRemasterX/zdrv.cpp
        PinballRemasterX/zdrv.h
        PinballRemasterX/imconfig.h
        PinballRemasterX/imgui_internal.h
        PinballRemasterX/imgui.cpp
        PinballRemasterX/imgui.h
        PinballRemasterX/imgui_sdl.cpp
        PinballRemasterX/imgui_sdl.h
        PinballRemasterX/imgui_draw.cpp
        PinballRemasterX/imgui_widgets.cpp
        PinballRemasterX/imgui_tables.cpp
        PinballRemasterX/imgui_demo.cpp
        PinballRemasterX/imgui_impl_sdl.cpp
        PinballRemasterX/imgui_impl_sdl.h
        PinballRemasterX/imstb_textedit.h
        PinballRemasterX/imstb_rectpack.h
        PinballRemasterX/imstb_truetype.h
        PinballRemasterX/DebugOverlay.cpp
        PinballRemasterX/DebugOverlay.h
        )

# On Windows, include resource file with the icon
if(WIN32)
    set_source_files_properties(PinballRemasterX/PinballRemasterX.rc LANGUAGE RC)
    list(APPEND SOURCE_FILES PinballRemasterX/PinballRemasterX.rc)
endif(WIN32)

add_executable(PinballRemasterX ${SOURCE_FILES})

# Skip pch on foreign code
set_source_files_properties(
        PinballRemasterX/imgui.cpp
        PinballRemasterX/imgui_sdl.cpp
        PinballRemasterX/imgui_draw.cpp
        PinballRemasterX/imgui_widgets.cpp
        PinballRemasterX/imgui_tables.cpp
        PinballRemasterX/imgui_demo.cpp
        PinballRemasterX/imgui_impl_sdl.cpp
        PROPERTIES SKIP_PRECOMPILE_HEADERS 1
)

if(${CMAKE_VERSION} VERSION_GREATER "3.16.0" OR ${CMAKE_VERSION} VERSION_EQUAL "3.16.0")
    target_precompile_headers(PinballRemasterX
            PUBLIC
            PinballRemasterX/pch.h
            )
endif()

target_link_libraries(PinballRemasterX ${SDL2_LIBRARY} ${SDL2_MIXER_LIBRARY})

# On Windows, copy DLL to output
if(WIN32)
    list(GET SDL2_LIBRARY -1 SDL2_DLL_PATH)
    list(GET SDL2_MIXER_LIBRARY -1 SDL2_MIXER_DLL_PATH)
    get_filename_component(SDL2_DLL_PATH ${SDL2_DLL_PATH} DIRECTORY)
    get_filename_component(SDL2_MIXER_DLL_PATH ${SDL2_MIXER_DLL_PATH} DIRECTORY)
    if(MINGW)
        string(REGEX REPLACE "lib$" "bin" SDL2_DLL_PATH ${SDL2_DLL_PATH})
        string(REGEX REPLACE "lib$" "bin" SDL2_MIXER_DLL_PATH ${SDL2_MIXER_DLL_PATH})
    endif()
    message(STATUS "copy paths='${SDL2_DLL_PATH}' '${SDL2_MIXER_DLL_PATH}' '${GAME_DATA_FILES}' '${GAME_DATA_SOUNDS}") 
    add_custom_command(TARGET PinballRemasterX POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different "${SDL2_DLL_PATH}/SDL2.dll" $<TARGET_FILE_DIR:PinballRemasterX>
        COMMAND ${CMAKE_COMMAND} -E copy_if_different "${SDL2_MIXER_DLL_PATH}/SDL2_mixer.dll" $<TARGET_FILE_DIR:PinballRemasterX>
        COMMAND ${CMAKE_COMMAND} -E copy_if_different "${GAME_DATA_FILES}/PINBALLREMASTERX.DAT" $<TARGET_FILE_DIR:PinballRemasterX>
        COMMAND ${CMAKE_COMMAND} -E copy_directory "${GAME_DATA_SOUNDS}" $<TARGET_FILE_DIR:PinballRemasterX>/SOUND
        )
endif()