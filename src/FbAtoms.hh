// FbAtom.hh
// Copyright (c) 2002 Henrik Kinnunen (fluxgen@linuxmail.org)
//
// Permission is hereby granted, free of charge, to any person obtaining a
// copy of this software and associated documentation files (the "Software"),
// to deal in the Software without restriction, including without limitation
// the rights to use, copy, modify, merge, publish, distribute, sublicense,
// and/or sell copies of the Software, and to permit persons to whom the
// Software is furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
// THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
// FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
// DEALINGS IN THE SOFTWARE.

// $Id: FbAtoms.hh,v 1.8 2002/12/01 13:41:56 rathnor Exp $
#ifndef FBATOMS_HH
#define FBATOMS_HH

#include <X11/Xlib.h>
#include <X11/Xatom.h>

/**
	atom handler for base atoms
*/
class FbAtoms {
public:
    explicit FbAtoms(Display *display);
    virtual ~FbAtoms();
    static FbAtoms *instance();


    inline Atom getWMChangeStateAtom() const { return xa_wm_change_state; }
    inline Atom getWMStateAtom() const { return xa_wm_state; }
    inline Atom getWMDeleteAtom() const { return xa_wm_delete_window; }
    inline Atom getWMProtocolsAtom() const { return xa_wm_protocols; }
    inline Atom getWMTakeFocusAtom() const { return xa_wm_take_focus; }
    inline Atom getWMColormapAtom() const { return xa_wm_colormap_windows; }
    inline Atom getMotifWMHintsAtom() const { return motif_wm_hints; }

    // this atom is for normal app->WM hints about decorations, stacking,
    // starting workspace etc...
    inline Atom getFluxboxHintsAtom() const { return blackbox_hints;}

    // these atoms are for normal app->WM interaction beyond the scope of the
    // ICCCM...
    inline Atom getFluxboxAttributesAtom() const	{ return blackbox_attributes; }
    inline Atom getFluxboxChangeAttributesAtom() const { return blackbox_change_attributes; }

    // these atoms are for window->WM interaction, with more control and
    // information on window "structure"... common examples are
    // notifying apps when windows are raised/lowered... when the user changes
    // workspaces... i.e. "pager talk"
    inline Atom getFluxboxStructureMessagesAtom() const{ return blackbox_structure_messages; }

    // *Notify* portions of the NETStructureMessages protocol
    inline Atom getFluxboxNotifyStartupAtom() const { return blackbox_notify_startup; }
    inline Atom getFluxboxNotifyWindowAddAtom() const { return blackbox_notify_window_add; }
    inline Atom getFluxboxNotifyWindowDelAtom() const { return blackbox_notify_window_del; }
    inline Atom getFluxboxNotifyWindowFocusAtom() const { return blackbox_notify_window_focus; }
    inline Atom getFluxboxNotifyCurrentWorkspaceAtom() const { return blackbox_notify_current_workspace; }
    inline Atom getFluxboxNotifyWorkspaceCountAtom() const { return blackbox_notify_workspace_count; }
    inline Atom getFluxboxNotifyWindowRaiseAtom() const { return blackbox_notify_window_raise; }
    inline Atom getFluxboxNotifyWindowLowerAtom() const { return blackbox_notify_window_lower; }

    // atoms to change that request changes to the desktop environment during
    // runtime... these messages can be sent by any client... as the sending
    // client window id is not included in the ClientMessage event...
    inline Atom getFluxboxChangeWorkspaceAtom() const { return blackbox_change_workspace; }
    inline Atom getFluxboxChangeWindowFocusAtom() const { return blackbox_change_window_focus; }
    inline Atom getFluxboxCycleWindowFocusAtom() const { return blackbox_cycle_window_focus; }

private:
    void initAtoms(Display *disp);
// NETAttributes
    Atom blackbox_attributes, blackbox_change_attributes, blackbox_hints;

    // NETStructureMessages
    Atom blackbox_structure_messages, blackbox_notify_startup,
        blackbox_notify_window_add, blackbox_notify_window_del,
        blackbox_notify_window_focus, blackbox_notify_current_workspace,
        blackbox_notify_workspace_count, blackbox_notify_window_raise,
        blackbox_notify_window_lower;

    // message_types for client -> wm messages
    Atom blackbox_change_workspace, blackbox_change_window_focus,
        blackbox_cycle_window_focus;

    Atom xa_wm_colormap_windows, xa_wm_protocols, xa_wm_state,
        xa_wm_delete_window, xa_wm_take_focus, xa_wm_change_state,
        motif_wm_hints;
    bool m_init;
    static FbAtoms *s_singleton;
};

#endif //FBATOMS_HH
