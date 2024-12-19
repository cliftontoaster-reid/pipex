# Pipex

**Pipex** is a school 42 project where the command, pipex, used in the following way:

```shell
pipex [input_file] [command_1] [command_2] [output_file]
```

The goal is to read the `input_file` and send it to `command_1` as a pipe before doing
the same with the output of `command_1` to `command_2` and finally write the output of
`command_2` to `output_file`.

## Steps

### 1. Executing a command

One of the hardest parts to this project is to execute a command and sending it to its
stdin, and returning its stdout.

For this purpose, the [`cmd.c` file](cmd.c) was created.

The function `cmd_init` receives a command and its arguments and returns a pointer to a
`t_cmd` struct.

It is then possible to use the `cmd_exec_stdin` to execute the command with args, environment variables, and with text to send via stdin.

