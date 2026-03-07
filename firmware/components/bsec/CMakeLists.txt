idf_component_register(
    SRCS "config/bsec_iaq.c"
    INCLUDE_DIRS "include" "config"
)

target_link_libraries(${COMPONENT_LIB} PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/lib/libalgobsec.a
)
