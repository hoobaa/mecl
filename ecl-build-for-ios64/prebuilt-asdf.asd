
(DEFSYSTEM "prebuilt-asdf" :CLASS ASDF::PREBUILT-SYSTEM :LIB #P"SYS:LIBASDF.A" :DEPENDS-ON ("cmp") :COMPONENTS ((:COMPILED-FILE "prebuilt-asdf" :PATHNAME #P"SYS:ASDF"))) 