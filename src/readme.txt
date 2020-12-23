
Use Visual Studio 2015, because game is built with this VS version.
This way, we don't need to install additional vc++ runtime.

Game is 32-bit, so we build 32-bit dll.

0. Disable precompiled headers (Project properties -> C/C++ -> Precompiled headers -> Precompiled header = Not using)
1. Disable incremental linking (Project properties -> Linker -> General -> Enable Incremental Linking = No)
2. Disable Safe SEH (Project properties -> Linker -> Advanced -> Image Has Safe Exception Handlers = No)
3. Enable ASM (Project -> Build Customizations -> masm = selected)
4. Add asm file to project
5. Specify module definition file (Project properties -> Linker -> Input -> Module Definition File = module.def)
6. Set target name (Project properties -> General -> Target Name = opengl32)
7. Build
