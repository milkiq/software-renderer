add_requires("xege")

target("core")
    set_kind("static")
    add_packages("xege")
    set_license("LGPL-3.0")
    add_deps("wmath")
    add_files("src/*.cpp")
    add_includedirs("include", {public = true})