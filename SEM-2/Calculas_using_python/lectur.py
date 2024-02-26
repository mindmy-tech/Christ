import sys
import os

class Editor:
    def __init__(self):
        self.lines = ['wtf']  # Initial empty line
        self.cursor_x = 0
        self.cursor_y = 0

    def display(self):
        os.system('clear') if os.name == 'posix' else os.system('cls')
        for i, line in enumerate(self.lines):
            if i == self.cursor_y:
                sys.stdout.write(f"\033[7m{line[:self.cursor_x]}\033[m{line[self.cursor_x:]}\n")
            else:
                sys.stdout.write(line + '\n')

    def move_cursor_up(self):
        if self.cursor_y > 0:
            self.cursor_y -= 1
            self.cursor_x = min(self.cursor_x, len(self.lines[self.cursor_y]))

    def move_cursor_down(self):
        if self.cursor_y < len(self.lines) - 1:
            self.cursor_y += 1
            self.cursor_x = min(self.cursor_x, len(self.lines[self.cursor_y]))

    def move_cursor_left(self):
        if self.cursor_x > 0:
            self.cursor_x -= 1

    def move_cursor_right(self):
        if self.cursor_x < len(self.lines[self.cursor_y]):
            self.cursor_x += 1

    def run(self):
        while True:
            self.display()
            c = input("Press 'q' to quit. Use 'h', 'j', 'k', 'l' for cursor movement: ")

            if c == 'q':
                break
            elif c == 'k':
                self.move_cursor_up()
            elif c == 'j':
                self.move_cursor_down()
            elif c == 'h':
                self.move_cursor_left()
            elif c == 'l':
                self.move_cursor_right()

if __name__ == "__main__":
    editor = Editor()
    editor.run()
