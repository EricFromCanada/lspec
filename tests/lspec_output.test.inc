/*
* Testing the resulting output of test suite
*
* Must be run from the lspec.test.inc file
*/
local(test_desc) = "Properly outputs simply a test group in documentation format"
lspec_setupForTesting
describe("Something") => {}
if(lspec->result != "Something") => {
    stdoutnl('Test Failed\n' + #test_desc)
    stdoutnl(currentCapture->callStack->split('\n')->first)
    abort
}



#test_desc = "Properly outputs sub-test groups in documentation format"
lspec_setupForTesting
describe("Something") => {
    it("Does something") => {}
    describe("As an aspect") => {
        describe("Sub-aspect") => {}
        it("Does something cool") => {}
    }
    it("Does something else") => {}
}
local(my_result) = 'Something
' + lspec->indentor + 'Does something
' + lspec->indentor + 'Does something else
' + lspec->indentor + 'As an aspect
' + lspec->indentor + lspec->indentor + 'Does something cool
' + lspec->indentor + lspec->indentor + 'Sub-aspect'
if(lspec->result != #my_result) => {
    stdoutnl('Test Failed\n' + #test_desc)
    stdoutnl(currentCapture->callStack->split('\n')->first)
    abort
}



#test_desc = "Properly outputs a pending test in documentation format"
lspec_setupForTesting
describe("Something") => {
    it("does something") => {}
}
if(lspec->result != 'Something\n' + lspec->indentor + 'does something') => {
    stdoutnl('Test Failed\n' + #test_desc)
    stdoutnl(currentCapture->callStack->split('\n')->first)
    abort
}



#test_desc = "Properly outputs a basic successful test in documentation format"
lspec_setupForTesting
describe("Something") => {
    it("does something") => {
        expect(true)
    }
}
if(lspec->result != 'Something\n' + lspec->indentor + 'does something') => {
    stdoutnl('Test Failed\n' + #test_desc)
    stdoutnl(currentCapture->callStack->split('\n')->first)
    abort
}



#test_desc = "Properly outputs a basic failed test in documentation format"
lspec_setupForTesting
describe("Something") => {
    it("does something") => {
        expect(false)
    }
}
lspec->stop
local(expected_result) = 'Something\n' + lspec->indentor + 'does something (FAILED - 1)

Failures:

' + lspec->indentor + '1) Something does something
' + lspec->indentor + '   Failure/Error: expect(false)
' + lspec->indentor + '   ' + lspec->indentor + 'expected: true
' + lspec->indentor + '   ' + lspec->indentor + '     got: false
' + lspec->indentor + '   # 73:9 ' + currentCapture->callsite_file + '

Finished in ' + lspec->runTime + ' seconds
1 test, 1 failure'
if(lspec->result != #expected_result) => {
    stdoutnl('Test Failed\n' + #test_desc)
    stdoutnl(currentCapture->callStack->split('\n')->first)
    abort
}

//micros / 1000000.0