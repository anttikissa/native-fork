# native-fork

Exposes the POSIX syscall [fork(2)](https://en.wikipedia.org/wiki/Fork_(system_call)).

Only works in systems that have the said syscall.

Use at your own risk.

```js
const fork = require('native-fork')
const pid = fork()

if (pid) {
	console.log('I am the parent, child is', pid)
} else {
	console.log('I am the child')
}
```

## Caveats

Calling `fork(2)` probably breaks a lot of assumptions that Node.js makes and is therefore likely to
break things. For example, in the child process, `process.pid` still points to the parent's pid, as
demonstrated by this code:

```js
let fork = require('native-fork')
let cp = require('child_process')

let pid = fork()

if (pid) {
	console.log('parent: I am the parent, child is', pid)
	console.log('parent: Node.js thinks my pid is', process.pid)
	// Get the real pid by spawning a shell and asking it to tell its parent's pid:
	console.log(cp.execSync('echo "parent: actual pid is $PPID"').toString().trim())
} else {
	console.log('child: I am the child')
	console.log('child: Node.js thinks my pid is', process.pid)
	console.log(cp.execSync('echo "child: actual pid is $PPID"').toString().trim())
}
```
