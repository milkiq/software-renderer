set_project("SFRR")

add_rules("mode.debug", "mode.release")
add_requires("xege")
includes("core", "rasterizer", "wmath")

target("SFRR")
    set_license("LGPL-3.0")
    set_kind("binary")
    add_packages("xege")
    add_deps("core", "rasterizer", "wmath")
    add_files("src/*.cpp")
    set_languages("c++17")
