create_test_sourcelist(Tests
  lsqrCxxTests.cxx
  lsqrTest1.cxx
  lsqrTest2.cxx
  lsmrTest2.cxx
)

add_executable(lsqrCxxTests ${Tests})
target_link_libraries(lsqrCxxTests lsqr)

add_test(lsqrTest1 lsqrCxxTests lsqrTest1)
add_test(lsqrTest2 lsqrCxxTests lsqrTest2)
add_test(lsmrTest2 lsqrCxxTests lsmrTest2)

