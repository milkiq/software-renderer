target("core")
    set_kind("static")
    add_deps("wmath")
    add_files("src/*.cpp")
    add_includedirs("include", {public = true})