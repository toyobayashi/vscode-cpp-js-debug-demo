const asyncDemo = require('./build/Debug/VscodeCppJsDebugDemo')

asyncDemo((str) => {
  const msg = 'asyncDemo() ' + str
  console.log(msg)
})

console.log('[JavaScript] Call console.log()')
