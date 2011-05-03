
MITK_CREATE_MODULE_TESTS(LABELS MITK-Core)


include(mitkFunctionAddTestLabel)

# verify minimum expectations:
#   files are recognized as DICOM
#   loading files results in a given number of images
mitkAddCustomModuleTest(mitkDICOMTestingSanityTest_NoFiles mitkDICOMTestingSanityTest 0)
mitkAddCustomModuleTest(mitkDICOMTestingSanityTest_CTImage mitkDICOMTestingSanityTest 1 ${MITK_DATA_DIR}/spacing-ok-ct.dcm)
mitkAddCustomModuleTest(mitkDICOMTestingSanityTest_MRImage mitkDICOMTestingSanityTest 1 ${MITK_DATA_DIR}/spacing-ok-mr.dcm)
mitkAddCustomModuleTest(mitkDICOMTestingSanityTest_SCImage mitkDICOMTestingSanityTest 1 ${MITK_DATA_DIR}/spacing-ok-sc.dcm)

set(VERIFY_DUMP_CMD  ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/VerifyDICOMMitkImageDump)

set(CT_ABDOMEN_DIR ${MITK_DATA_DIR}/TinyCTAbdomen)

# these variables could be passed as parameters to a generic test creation function
set(CURRENT_DATASET_DIR ${CT_ABDOMEN_DIR})
set(TESTS_DIR Tests)
set(INPUT_LISTNAME input)
set(EXPECTED_DUMP expected.dump)

file(GLOB_RECURSE allInputs ${CURRENT_DATASET_DIR}/${TESTS_DIR}/*/${INPUT_LISTNAME})

function(expectFileExists filename)
  if (NOT EXISTS ${filename})
    message(SEND_ERROR "Test case expected file ${filename} which does not exist! Please fix your CMake code or file layout.")
  endif (NOT EXISTS ${filename})
endfunction(expectFileExists)

foreach(input ${allInputs})
  string(REGEX REPLACE ".*${TESTS_DIR}/([^/]+)/.*" "\\1" input ${input})
  set(inputfilelist "${CURRENT_DATASET_DIR}/${TESTS_DIR}/${input}/${INPUT_LISTNAME}")
  set(expecteddump "${CURRENT_DATASET_DIR}/${TESTS_DIR}/${input}/${EXPECTED_DUMP}")
  set(testname "DICOM_Load_${input}")

  message(STATUS "DICOM loading test case '${input}'")
  expectFileExists(${inputfilelist})
  expectFileExists(${expecteddump})

  # TODO provide error messages if input not valid

  set(dicomFiles) # clear list
  file(STRINGS ${inputfilelist} rawDicomFiles)
  foreach(raw ${rawDicomFiles})
    set(fileWithFullPath ${CURRENT_DATASET_DIR}/${raw})
    list(APPEND dicomFiles ${fileWithFullPath})
  endforeach(raw ${rawDicomFiles})

  #message(STATUS "  Load ${dicomFiles}")
  add_test(${testname}
           ${VERIFY_DUMP_CMD} ${expecteddump} ${dicomFiles})
  mitkFunctionAddTestLabel(${testname})

endforeach(input allInputs)

