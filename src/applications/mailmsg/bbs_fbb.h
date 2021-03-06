/*
   BBS access API for FBB
   (c) 2020 by Martin Cooper KD6YAM

   This program is free software; you can redistribute it and/or
   modify it under the terms of the GNU General Public License
   as published by the Free Software Foundation; either version
   2 of the license, or (at your option) any later version.
*/

class FBB : public BBS {
    public:
        FBB(char* homebbs, char* homecall, char* mailhome);
        virtual ~FBB();

        virtual void save_msg(int num, bool pers, char* data, unsigned long length);

        virtual int get_one_message(FILE *fin, char **buf, int *bsize, char *title);
        virtual void wait_prompt(FILE *fin);
        virtual void send_request(int num);
        virtual void send_tag();
};

