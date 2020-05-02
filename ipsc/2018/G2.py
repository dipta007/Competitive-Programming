import subprocess
# process = subprocess.Popen(['git', 'ls-tree', '-r', '--name-only f3a57af82'], stdout=subprocess.PIPE)
# stdout = process.communicate()[0]
# print(stdout)

def git(*args):
    return subprocess.Popen(['git'] + list(args))

process = git('ls-tree', '-r', '--name-only', ' f3a57af82')

while True:
    output = process.stdout.readline()
    if output == '' and process.poll() is not None:
        break
    if output:
        print(output)
    rc = process.poll()