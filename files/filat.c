#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <time.h>

const char* getInputFileType(struct stat attributes){

  if(S_ISREG(attributes.st_mode))
  {
    return "regular file";
  }

  if(S_ISDIR(attributes.st_mode))
  {
      return "dir";
  }

  if(S_ISCHR(attributes.st_mode))
  {
      return "character device";
  }

  if(S_ISLNK(attributes.st_mode))
  {
    return "symlink";
  }

  if(S_ISFIFO(attributes.st_mode))
  {
      return "fifo";
  }

   if(S_ISBLK(attributes.st_mode))
  {
      return "block device";
  }


  return "unknown";
}

int main(int argc, char const *argv[]) {
  struct stat attributes;

  if(stat(argv[1], &attributes) == 0){
    printf("------------------------ %s --------------------\n", argv[1]);
    printf("File type                : %s\n", getInputFileType(attributes));
    printf("Access privileges        : ");
    printf( (S_ISDIR(attributes.st_mode)) ? "d" : "-");
    printf( (attributes.st_mode & S_IRUSR) ? "r" : "-");
    printf( (attributes.st_mode & S_IWUSR) ? "w" : "-");
    printf( (attributes.st_mode & S_IXUSR) ? "x" : "-");
    printf( (attributes.st_mode & S_IRGRP) ? "r" : "-");
    printf( (attributes.st_mode & S_IWGRP) ? "w" : "-");
    printf( (attributes.st_mode & S_IXGRP) ? "x" : "-");
    printf( (attributes.st_mode & S_IROTH) ? "r" : "-");
    printf( (attributes.st_mode & S_IWOTH) ? "w" : "-");
    printf( (attributes.st_mode & S_IXOTH) ? "x" : "-");
    printf("\n");
    printf("inode-Number             : %ld\n",(long) attributes.st_ino);
    printf("Link count               : %ld\n",(long) attributes.st_nlink);
    printf("UID                      : %ld\n",(long) attributes.st_uid);
    printf("GID                      : %ld\n",(long) attributes.st_gid);
    printf("File size                : %lld\n",(long long) attributes.st_size);
    printf("Last access              : %s",ctime(&attributes.st_atime));
    printf("Last modification        : %s",ctime(&attributes.st_mtime));
    printf("Last inode change        : %s",ctime(&attributes.st_ctime));
  }

  else{
    printf("file '%s' does not exist!!!!\n", argv[1]);
  }

  return 0;
}