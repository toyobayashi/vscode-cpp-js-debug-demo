const asyncDemo: (callback: (str: string) => void) => void = require('./build/Debug/VscodeCppJsDebugDemo')

asyncDemo((str) => {
  const msg = 'asyncDemo() ' + str
  console.log(msg)
})

console.log('[TypeScript] Call console.log()')
