{
  s16  tmp;

  tmp = buff >> 8;
  n_aLoadADPCM(ptr++, 32, osVirtualToPhysical(lp->fcvec.fccoef));
  n_aPoleFilter(ptr++, lp->first, lp->fgain, tmp, osVirtualToPhysical(lp->fstate));
}
