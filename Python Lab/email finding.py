import re

pattern = r"[a-zA-Z0-9.-]+@[a-zA-Z0-9.-]+"
compiled_pattern = re.compile(pattern)

text = """
Here are some emails:
doe1220@my-email.org
support@bowebsite.net
"""

matches = compiled_pattern.findall(text)
print(matches)
