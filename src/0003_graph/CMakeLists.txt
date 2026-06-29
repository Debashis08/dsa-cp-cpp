# Specify the source files
set(0003GRAPH_SOURCES
    0001_bfs.cc

)

# Create a library target
add_library(0003_Graph ${0003GRAPH_SOURCES})

target_include_directories(0003_Graph PUBLIC 
    ${CMAKE_CURRENT_SOURCE_DIR}/headers
)