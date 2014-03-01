/*
  LinPac Mailer
  (c) 1998 - 1999 by Radek Burget OK2JBG (xburge01@stud.fee.vutbr.cz)

  This program is free software; you can redistribute it and/or
  modify it under the terms of the GNU General Public License
  as published by the Free Software Foundation; either version
  2 of the license, or (at your option) any later version.

  mail_help.cc - help window
*/
#include <string.h>
#include <ctype.h>
#include <ncurses.h>

#include "mail_help.h"

//=========================================================================
// Class HelpWindow
//=========================================================================
HelpWindow::HelpWindow(void *pwin, int height, int width, int wy, int wx)
{
  xsize = width;
  ysize = height;
  x = wx;
  y = wy;
  max_pages = 4;
  page = 1;

  //WINDOW *win = subwin(reinterpret_cast<WINDOW *>(pwin), ysize, xsize, y, x);
  WINDOW *win = reinterpret_cast<WINDOW *>(pwin);
  mwin = win;
  keypad(win, true);
  meta(win, true);
  nodelay(win, true);

  wbkgdset(win, ' ' | COLOR_PAIR(C_TEXT) | A_BOLD);
  werase(win);
  box(win, ACS_VLINE, ACS_HLINE);
  mvwprintw(win, 0, 2, "Help");

  show();
}

void HelpWindow::show()
{
  draw(true);
  old_focus_window = focus_window;
  focus_window = mwin;
  old_focused = focused;
  focused = this;
  help(HELP_HELP);
}

void HelpWindow::draw(bool all)
{
  WINDOW *win = reinterpret_cast<WINDOW *>(mwin);

  if (all)
  {
    wbkgdset(win, ' ' | COLOR_PAIR(C_TEXT) | A_BOLD);
    werase(win);
    box(win, ACS_VLINE, ACS_HLINE);
    mvwprintw(win, 0, 2, "Help");
  }

  wbkgdset(win, ' ' | COLOR_PAIR(C_SELECT) | A_BOLD);
  mvwprintw(win, 1, CENTER(18), "LinPac Mailer Help");

  if (page == 1)
  {
     wbkgdset(win, ' ' | COLOR_PAIR(C_UNSELECT) | A_BOLD);
     mvwprintw(win,  4, 2, "Message list window");
     wbkgdset(win, ' ' | COLOR_PAIR(C_TEXT) | A_BOLD);
     mvwprintw(win,  5, 2, "Space ... select/unselect current");
     mvwprintw(win,  6, 2, "Enter ... view current message");
     mvwprintw(win,  7, 2, "Ctrl-X .. delete selected messages");
     mvwprintw(win,  8, 2, "F ... select bulletins      P ... show/hide private messages");
     mvwprintw(win,  9, 2, "T ... toggle translation    D ... download selected messages");
     mvwprintw(win, 10, 2, "C ... compose new message   I ... toggle incomming/outgoing");
     mvwprintw(win, 11, 2, "Q ... quit");

     wbkgdset(win, ' ' | COLOR_PAIR(C_UNSELECT) | A_BOLD);
     mvwprintw(win, 14, 2, "Bulletin selection window");
     wbkgdset(win, ' ' | COLOR_PAIR(C_TEXT) | A_BOLD);
     mvwprintw(win, 15, 2, "Up, Down, PgUp, PgDn, TAB .... move through the lists");
     mvwprintw(win, 16, 2, "Enter, ESC ................... accept selection");
     mvwprintw(win, 17, 2, "Space ........................ select current bulletin");
     mvwprintw(win, 18, 2, "* ............................ invert bulletin selection");
     mvwprintw(win, 19, 2, "A ............................ new group from selected");
     mvwprintw(win, 20, 2, "D ............................ delete group");
  }

  if (page == 2)
  {
     wbkgdset(win, ' ' | COLOR_PAIR(C_UNSELECT) | A_BOLD);
     mvwprintw(win,  4, 2, "Message viewer window");
     wbkgdset(win, ' ' | COLOR_PAIR(C_TEXT) | A_BOLD);
     mvwprintw(win,  5, 2, "Cursor keys, PgUp, PgDn ... move through the message");
     mvwprintw(win,  6, 2, "W ......................... toggle line wrapping");
     mvwprintw(win,  7, 2, "H ......................... toggle message header");
     mvwprintw(win,  8, 2, "T ......................... toggle character translation");
     mvwprintw(win, 10, 2, "R ......................... reply to this message (personal message)");
     mvwprintw(win, 11, 2, "C ......................... comment this message (bulletin)");
     mvwprintw(win, 12, 2, "F ......................... forward this message to another dest.");
     mvwprintw(win, 14, 2, "S ......................... save message to text file");
     mvwprintw(win, 15, 2, "X ......................... export attachment to file");
     mvwprintw(win, 16, 2, "L or ESC .................. back to message list");
  }

  if (page == 3)
  {
     wbkgdset(win, ' ' | COLOR_PAIR(C_UNSELECT) | A_BOLD);
     mvwprintw(win, 4, 2, "Mail composer");
     wbkgdset(win, ' ' | COLOR_PAIR(C_TEXT) | A_BOLD);
     mvwprintw(win, 5, 2, "Cursor keys ...... navigate through text");
     mvwprintw(win, 6, 2, "DEL, Backspace ... delete current/previous charactes");
     mvwprintw(win, 7, 2, "Ctrl-Y ........... delete current line");
     mvwprintw(win, 8, 2, "Ctrl-T ........... insert current time");
     mvwprintw(win, 9, 2, "Ctrl-D ........... insert current date");

     mvwprintw(win, 11, 2, "Ctrl-A ........... cancel the message");
     mvwprintw(win, 12, 2, "Ctrl-X ........... send the message");

     mvwprintw(win, 14, 2, "Ctrl-R ........... insert text file");
     mvwprintw(win, 15, 2, "Ctrl-E ........... export message to file");
     mvwprintw(win, 16, 2, "Ctrl-F ........... attach binary file");
  }

  if (page == 4)
  {
     wbkgdset(win, ' ' | COLOR_PAIR(C_TEXT) | A_BOLD);
     mvwprintw(win,  4, 2, "Use the :forward command to transfer new messages");
     mvwprintw(win,  5, 2, "to the BBS.");

     mvwprintw(win,  7, 2, "Use the :pack command to remove the messages marked");
     mvwprintw(win,  8, 2, "for delete.");

     mvwprintw(win, 10, 2, "You can switch to terminal mode anytime by pressing");
     mvwprintw(win, 12, 2, "F1 - F8 or F10 key. Then press Alt-<channel_number>");
     mvwprintw(win, 13, 2, "to switch back to the mailer running on some channel.");

     mvwprintw(win, 15, 2, "Message attachments (binary files) are processed after");
     mvwprintw(win, 16, 2, "sending the message by pressing Ctrl-X. Attached files");
     mvwprintw(win, 17, 2, "are converted to 7plus messages using the internal LinPac");
     mvwprintw(win, 18, 2, "command :sendfile. Files are split to blocks of the size");
     mvwprintw(win, 19, 2, "contained in BLOCK7P@0 variable.");
  }
  
  if (page == 1)
    mvwprintw(win, ysize-2, 2, "PageDown or Space - next page, ESC or L - return");
  else if (page == max_pages)
    mvwprintw(win, ysize-2, 2, "PageUp - previous page, ESC or L - return");
  else
    mvwprintw(win, ysize-2, 2, "PageDown or Space - next page, PageUp - previous page, ESC or L - return");
  
  wnoutrefresh(win);
  for (int i = 0; i < 5; i++) doupdate(); //must be done many times, don't know why
}

void HelpWindow::handle_event(Event *ev)
{
  if (ev == NULL) return;
  if (ev->type == EV_KEY_PRESS)
  {
    if (toupper(ev->x) == 'Q')
    {
      focused = NULL; //exit immediatelly
    }

    if (ev->x == KEY_NPAGE || ev->x == ' ')
    {
      if (page < max_pages) page++;
      draw(true);
    }

    if (ev->x == KEY_PPAGE)
    {
      if (page > 1) page--;
      draw(true);
    }

    if (ev->x == '\x1b' || toupper(ev->x) == 'L')
    {
      focus_window = old_focus_window;
      focused = old_focused;
      focused->handle_event(NULL);
      focused->draw(true);
      help(HELP_LIST);
    }
    else draw();
  }
}

