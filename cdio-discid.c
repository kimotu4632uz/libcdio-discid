#include <stdio.h>
#include <inttypes.h>
#include <cdio/cdio.h>

static int cddb_dec_digit_sum(int n) {
  int ret=0;
  
  while (1) {
    ret += n%10;
    n    = n/10;
    if (!n) return ret;
  }
}

uint32_t cddb_discid(CdIo_t *p_cdio, track_t i_tracks) {
  int i,t,n=0;
  msf_t start_msf;
  msf_t msf;
  
  for (i = 1; i <= i_tracks; i++) {
    cdio_get_track_msf(p_cdio, i, &msf);
    n += cddb_dec_digit_sum(cdio_audio_get_msf_seconds(&msf));
  }

  cdio_get_track_msf(p_cdio, 1, &start_msf);
  cdio_get_track_msf(p_cdio, CDIO_CDROM_LEADOUT_TRACK, &msf);
  
  t = cdio_audio_get_msf_seconds(&msf)-cdio_audio_get_msf_seconds(&start_msf);
  
  return ((n % 0xff) << 24 | t << 8 | i_tracks);
}

int main() {
  CdIo_t* p_cdio = cdio_open_am(NULL, DRIVER_UNKNOWN, NULL);

  if (p_cdio == NULL) {
    fprintf(stderr, "Error in automatically selecting driver.\n");
    cdio_destroy(p_cdio);
    return -1;
  }

  track_t i_tracks = cdio_get_num_tracks(p_cdio);

  if (i_tracks == CDIO_INVALID_TRACK) {
    fprintf(stderr, "Cannot get number of tracks\n");
    cdio_destroy(p_cdio);
    return -2;
  }

  printf("%"PRIX32"\n", cddb_discid(p_cdio, i_tracks));
  return 0;
}
