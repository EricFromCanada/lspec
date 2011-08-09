// Expect extensions
local(test_desc) = "[expect->error] raises an error if it's not passed a block"
lspec_setupForTesting
describe("Something") => {
    it("Does something") => {
        try => {
            local(success) = false
            handle(error_code == error_code_missingGivenBlock &&
                   error_msg  == error_msg_missingGivenBlock) => 
            { #success = true }
            expect->error(error_code_lspecNotInTestGroup, error_msg_lspecNotInTestGroup)
        }
    }
}
if(not #success) => {
    stdoutnl('Test Failed\n' + #test_desc)
    stdoutnl(currentCapture->callStack->split('\n')->first)
    abort
}
if(lspec->numTests != 1) => {
    stdoutnl('Test Failed\n' + #test_desc)
    stdoutnl(currentCapture->callStack->split('\n')->first)
    abort
}
if(lspec->numPending != 0) => {
    stdoutnl('Test Failed\n' + #test_desc)
    stdoutnl(currentCapture->callStack->split('\n')->first)
    abort
}
if(lspec->numSuccesses != 0) => {
    stdoutnl('Test Failed\n' + #test_desc)
    stdoutnl(currentCapture->callStack->split('\n')->first)
    abort
}
if(lspec->numFailures != 1) => {
    stdoutnl('Test Failed\n' + #test_desc)
    stdoutnl(currentCapture->callStack->split('\n')->first)
    abort
}



#test_desc = "[expect->error] passes when it gets the expected error"
lspec_setupForTesting
describe("Something") => {
    it("Does something") => {
        expect->error(error_code_lspecNotInTestGroup, error_msg_lspecNotInTestGroup) => {
            fail(error_code_lspecNotInTestGroup, error_msg_lspecNotInTestGroup)
        }
    }
}
if(lspec->numTests != 1) => {
    stdoutnl('Test Failed\n' + #test_desc)
    stdoutnl(currentCapture->callStack->split('\n')->first)
    abort
}
if(lspec->numPending != 0) => {
    stdoutnl('Test Failed\n' + #test_desc)
    stdoutnl(currentCapture->callStack->split('\n')->first)
    abort
}
if(lspec->numSuccesses != 1) => {
    stdoutnl('Test Failed\n' + #test_desc)
    stdoutnl(currentCapture->callStack->split('\n')->first)
    abort
}
if(lspec->numFailures != 0) => {
    stdoutnl('Test Failed\n' + #test_desc)
    stdoutnl(currentCapture->callStack->split('\n')->first)
    abort
}



#test_desc = "[expect->error] fails when it gets an unexpected error & re-raises it"
lspec_setupForTesting
describe("Something") => {
    it("Does something") => {
        try => {
            local(success) = false
            handle(error_code == error_code_divideByZero &&
                   error_msg  == error_msg_divideByZero) => 
            { #success = true }
            expect->error(error_code_lspecNotInTestGroup, error_msg_lspecNotInTestGroup) => {
                5/0
            }
        }
    }
}
if(not #success) => {
    stdoutnl('Test Failed\n' + #test_desc)
    stdoutnl(currentCapture->callStack->split('\n')->first)
    abort
}
if(lspec->numTests != 1) => {
    stdoutnl('Test Failed\n' + #test_desc)
    stdoutnl(currentCapture->callStack->split('\n')->first)
    abort
}
if(lspec->numPending != 0) => {
    stdoutnl('Test Failed\n' + #test_desc)
    stdoutnl(currentCapture->callStack->split('\n')->first)
    abort
}
if(lspec->numSuccesses != 0) => {
    stdoutnl('Test Failed\n' + #test_desc)
    stdoutnl(currentCapture->callStack->split('\n')->first)
    abort
}
if(lspec->numFailures != 1) => {
    stdoutnl('Test Failed\n' + #test_desc)
    stdoutnl(currentCapture->callStack->split('\n')->first)
    abort
}



#test_desc = "[expect->error] fails when it doesn't get any error"
lspec_setupForTesting
describe("Something") => {
    it("Does something") => {
        expect->error(error_code_lspecNotInTestGroup, error_msg_lspecNotInTestGroup) => {}
    }
}
if(lspec->numTests != 1) => {
    stdoutnl('Test Failed\n' + #test_desc)
    stdoutnl(currentCapture->callStack->split('\n')->first)
    abort
}
if(lspec->numPending != 0) => {
    stdoutnl('Test Failed\n' + #test_desc)
    stdoutnl(currentCapture->callStack->split('\n')->first)
    abort
}
if(lspec->numSuccesses != 0) => {
    stdoutnl('Test Failed\n' + #test_desc)
    stdoutnl(currentCapture->callStack->split('\n')->first)
    abort
}
if(lspec->numFailures != 1) => {
    stdoutnl('Test Failed\n' + #test_desc)
    stdoutnl(currentCapture->callStack->split('\n')->first)
    abort
}


// [expect->stdout] //
#test_desc = "[expect->stdout] raises an error if it's not passed a block"
lspec_setupForTesting
describe("Something") => {
    it("Does something") => {
        try => {
            local(success) = false
            handle(error_code == error_code_missingGivenBlock &&
                   error_msg  == error_msg_missingGivenBlock) => 
            { #success = true }
            expect->stdout('Lager, sir, is regal.')
        }
    }
}
if(not #success) => {
    stdoutnl('Test Failed\n' + #test_desc)
    stdoutnl(currentCapture->callStack->split('\n')->first)
    abort
}
if(lspec->numTests != 1) => {
    stdoutnl('Test Failed\n' + #test_desc)
    stdoutnl(currentCapture->callStack->split('\n')->first)
    abort
}
if(lspec->numPending != 0) => {
    stdoutnl('Test Failed\n' + #test_desc)
    stdoutnl(currentCapture->callStack->split('\n')->first)
    abort
}
if(lspec->numSuccesses != 0) => {
    stdoutnl('Test Failed\n' + #test_desc)
    stdoutnl(currentCapture->callStack->split('\n')->first)
    abort
}
if(lspec->numFailures != 1) => {
    stdoutnl('Test Failed\n' + #test_desc)
    stdoutnl(currentCapture->callStack->split('\n')->first)
    abort
}



#test_desc = "[expect->stdout] passes when it gets the expected data sent to stdout"
lspec_setupForTesting
describe("Something") => {
    it("Does something") => {
        // Need to make sure it's not sending anything to stdout
        // save stdout using ->dup
        // create a local conduit
        // close real stout, reopen it on our write pipe using dup2 system call
        // make a file object here which we read stout from
        local(saveStdout = file_stdout->fd->dup)
        local(readFd, writeFd) = io_file_pipe
        #writeFd->dup2(file_stdout->fd)
        local(readTest = file(#readFd))
        
        handle => {
            // set stout back using our save
            #saveStdout->dup2(file_stdout->fd)
        }
        
        expect->stdout('Lager, sir, is regal.') => {
            stdout('Lager, sir, is regal.')
        }
        
        // read test data
        local(didRead = #readTest->readString)
    }
}
if(#didRead != '') => {
    stdoutnl('Test Failed\n' + #test_desc)
    stdoutnl(currentCapture->callStack->split('\n')->first)
    abort
}
if(lspec->numTests != 1) => {
    stdoutnl('Test Failed\n' + #test_desc)
    stdoutnl(currentCapture->callStack->split('\n')->first)
    abort
}
if(lspec->numPending != 0) => {
    stdoutnl('Test Failed\n' + #test_desc)
    stdoutnl(currentCapture->callStack->split('\n')->first)
    abort
}
if(lspec->numSuccesses != 1) => {
    stdoutnl('Test Failed\n' + #test_desc)
    stdoutnl(currentCapture->callStack->split('\n')->first)
    abort
}
if(lspec->numFailures != 0) => {
    stdoutnl('Test Failed\n' + #test_desc)
    stdoutnl(currentCapture->callStack->split('\n')->first)
    abort
}



#test_desc = "[expect->stdout] fails when it gets an unexpected error & re-raises it"
lspec_setupForTesting
describe("Something") => {
    it("Does something") => {
        try => {
            local(success) = false
            handle(error_code == error_code_divideByZero &&
                   error_msg  == error_msg_divideByZero) => 
            { #success = true }
            expect->stdout('Lager, sir, is regal.') => {
                5/0
            }
        }
    }
}
if(not #success) => {
    stdoutnl('Test Failed\n' + #test_desc)
    stdoutnl(currentCapture->callStack->split('\n')->first)
    abort
}
if(lspec->numTests != 1) => {
    stdoutnl('Test Failed\n' + #test_desc)
    stdoutnl(currentCapture->callStack->split('\n')->first)
    abort
}
if(lspec->numPending != 0) => {
    stdoutnl('Test Failed\n' + #test_desc)
    stdoutnl(currentCapture->callStack->split('\n')->first)
    abort
}
if(lspec->numSuccesses != 0) => {
    stdoutnl('Test Failed\n' + #test_desc)
    stdoutnl(currentCapture->callStack->split('\n')->first)
    abort
}
if(lspec->numFailures != 1) => {
    stdoutnl('Test Failed\n' + #test_desc)
    stdoutnl(currentCapture->callStack->split('\n')->first)
    abort
}



#test_desc = "[expect->stdout] fails when stdout doesn't get the expected data"
lspec_setupForTesting
describe("Something") => {
    it("Does something") => {
        expect->stdout('Lager, sir, is regal.') => {}
    }
}
if(lspec->numTests != 1) => {
    stdoutnl('Test Failed\n' + #test_desc)
    stdoutnl(currentCapture->callStack->split('\n')->first)
    abort
}
if(lspec->numPending != 0) => {
    stdoutnl('Test Failed\n' + #test_desc)
    stdoutnl(currentCapture->callStack->split('\n')->first)
    abort
}
if(lspec->numSuccesses != 0) => {
    stdoutnl('Test Failed\n' + #test_desc)
    stdoutnl(currentCapture->callStack->split('\n')->first)
    abort
}
if(lspec->numFailures != 1) => {
    stdoutnl('Test Failed\n' + #test_desc)
    stdoutnl(currentCapture->callStack->split('\n')->first)
    abort
}