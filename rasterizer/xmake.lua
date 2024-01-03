add_requires("xege")

target("rasterizer")
    set_kind("static")
    set_license("LGPL-3.0")
    add_packages("xege")
    add_deps("wmath")
    add_files("src/*.cpp")
    add_includedirs("include", {public = true})