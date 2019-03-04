# native-fork

Exposes the POSIX syscall fork(2).

Only works in systems that have the said syscall.

Use at your own risk.

```
const fork = require('native-fork')
const pid = fork()

if (pid) {
	console.log('I am the parent, child is', pid)
} else {
	console.log('I am the child')
}
```
