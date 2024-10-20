#ifndef BANJO_KAZOOIE_CORE1_FRAMEBUFFERDRAW_H
#define BANJO_KAZOOIE_CORE1_FRAMEBUFFERDRAW_H

void framebufferdraw_drawSpriteCI4(s32 x, s32 y, BKSprite *sprite, s32 frame, s32 alpha_enabled);
void framebufferdraw_drawSpriteCI8(s32 x, s32 y, BKSprite *sprite, s32 frame, s32 alpha_enabled);
void framebufferdraw_drawSpriteRGBA16(s32 x, s32 y, BKSprite *sprite, s32 frame, bool alpha_enabled);
void framebufferdraw_drawSpriteI4(s32 x, s32 y, BKSprite *sprite, s32 frame, bool aplha_enabled);
void framebufferdraw_drawSpriteIA4(s32 x, s32 y, BKSprite *sprite, s32 frame, bool aplha_enabled);
void framebufferdraw_drawSpriteI8(s32 x, s32 y, BKSprite *sprite, s32 frame, s32 alpha_enabled);
void framebufferdraw_drawSpriteIA8(s32 x, s32 y, BKSprite *sprite, s32 frame, bool alpha_enabled);
void framebufferdraw_drawSpriteRGBA32(s32 x, s32 y, BKSprite *sprite, s32 frame, s32 alpha_enabled);
void framebufferdraw_stub1(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
void framebufferdraw_stub2(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
void framebufferdraw_drawTexture_CI4(s32 x, s32 y, void *tmem, s32 w, s32 h, bool alpha_enabled);
void framebufferdraw_draw(s32 x, s32 y, BKSprite *sprite, s32 frame, s32 alpha_enabled);
void framebufferdraw_func_80249DE0(s32 x, s32 y, s16 *arg2, s32 arg3, s32 arg4);
void framebufferdraw_func_80249F34(s32 x, s32 y, Struct84s* maskList, s32 maskIndex, s32 mX, s32 mY, s32 mW, s32 mH, s32 maskColor, s32 mStride, bool dim, s32 replacementColor);
void framebufferdraw_drawGrid(s32 x, s32 y, s32 arg2, s32 arg3, s32 horz_spacing, s32 vert_spacing);
void framebufferdraw_setPixel(s32 x, s32 y);
void framebufferdraw_drawOutline(s32 x, s32 y, s32 w, s32 h);
void framebufferdraw_func_8024A564(s32 x, s32 y, u16 *arg2, s32 arg3, s32 arg4, f32 arg5, f32 arg6);
void framebufferdraw_drawRect(s32 x, s32 y, s32 w, s32 h);
void framebufferdraw_resetPrimColorAndBuffer(void);
void framebufferdraw_setPrimColor(s32 r, s32 g, s32 b);
void framebufferdraw_setBufferIndex(s32 buffer_indx);
s32 framebufferdraw_getBufferIndex(void);

#endif
