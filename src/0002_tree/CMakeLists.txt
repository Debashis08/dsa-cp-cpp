# Specify the source files
set(0002TREE_SOURCES
    0001_segment_tree.cc

)

# Create a library target
add_library(0002_Tree ${0002TREE_SOURCES})

target_include_directories(0002_Tree PUBLIC 
    ${CMAKE_CURRENT_SOURCE_DIR}/headers
)