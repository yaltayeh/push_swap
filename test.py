import asyncio
import random
import os
i = 0
def rangen(len):
	array = random.sample(range(-2147483648, 2147483647), len)
	return array

async def run_subprocess(command):
	"""Run a subprocess asynchronously."""
	process = await asyncio.create_subprocess_exec(
		*command, stdout=asyncio.subprocess.PIPE, stderr=asyncio.subprocess.PIPE
	)

	# Wait for the process to complete and capture the output and error
	stdout, stderr = await process.communicate()

	return process.returncode, stdout.decode(), stderr.decode()

async def run_subprocess2(command):
	global i
	os.makedirs(f"log/{i}", exist_ok=True)
	args_file = f'log/{i}/args'
	stdout_file = f'log/{i}/steps'
	stderr_file = f'log/{i}/debug'
	i += 1
	with open(args_file, 'w') as args_f:
		args_f.write(" ".join(command[1:]))
		args_f.close()
	with open(stdout_file, 'w') as stdout_f, open(stderr_file, 'w') as stderr_f:
		process = await asyncio.create_subprocess_exec(
			*command, stdout=stdout_f, stderr=stderr_f
		)

		# Wait for the process to complete
		await process.communicate()
		stdout_f.close()
		stderr_f.close()
		return process.returncode

async def main():
	# Define commands for multiple subprocesses


	commands = []
	for _ in range(500):
		random_array = list(map(str, rangen(100)))
		commands.append(["./push_swap", *random_array])


	# Create asyncio tasks for subprocesses
	tasks = [run_subprocess2(command) for command in commands]

	# Run all subprocesses concurrently
	await asyncio.gather(*tasks)

# Run the async main function
if __name__ == "__main__":
	asyncio.run(main())
