
Game is 32-bit, so we build x86 dll (Release).

0. Disable precompiled headers (Project properties -> C/C++ -> Precompiled headers -> Precompiled header = Not using)
1. Disable incremental linking (Project properties -> Linker -> General -> Enable Incremental Linking = No)
2. Disable Safe SEH (Project properties -> Linker -> Advanced -> Image Has Safe Exception Handlers = No)
3. Enable ASM (Project -> Build Customizations -> masm = selected)
4. Add asm file to project
5. Specify module definition file (Project properties -> Linker -> Input -> Module Definition File = module.def)
6. Set target name (Project properties -> General -> Target Name = opengl32)
7. Remove runtime dependency (Project properties -> C/C++ -> Code generation -> Runtime Library = Multi-threaded(/MT))
8. Build
