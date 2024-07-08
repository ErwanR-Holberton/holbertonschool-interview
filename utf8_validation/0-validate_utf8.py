"""
validate utf8
"""

def validUTF8(data):
    """validate utf8"""
    for oct in data:
        if oct > 255:
            return False
    return True
