#include <common.h>
#include <usb.h>
#include <linux/usb/dwc3.h>

#include "xhci.h"

struct ltq_xhci {
	struct xhci_hccr *hcd;
	struct dwc3 *dwc3_reg;
};

static struct ltq_xhci ltq;
static unsigned long ctr_addr[] = { 0xba300000, 0xba500000};

static int ltq_xhci_core_init(struct ltq_xhci *ltq_xhci)
{
	int ret = 0;
	
	ret = dwc3_core_init(ltq_xhci->dwc3_reg);
	if (ret) {
		debug("%s:failed to initialize core\n", __func__);
		return ret;
	}

	/* We are hard-coding DWC3 core to Host Mode */
	dwc3_set_mode(ltq_xhci->dwc3_reg, DWC3_GCTL_PRTCAP_HOST);

	return 0;
}

int xhci_hcd_init(int index, struct xhci_hccr **hccr, struct xhci_hcor **hcor)
{
	struct ltq_xhci *ctx = &ltq;
	int ret;

	ctx->hcd = (struct xhci_hccr *)ctr_addr[index];
	ctx->dwc3_reg = (struct dwc3 *)((char *)(ctx->hcd) + DWC3_REG_OFFSET);

	ret = board_usb_init(index, USB_INIT_HOST);
	if (ret != 0) {
		puts("Failed to initialize board for USB\n");
		return ret;
	}

	ret = ltq_xhci_core_init(ctx);
	if (ret < 0) {
		puts("Failed to initialize xhci\n");
		return ret;
	}

	*hccr = (struct xhci_hccr *)ctx->hcd;
	*hcor = (struct xhci_hcor *)((uintptr_t) *hccr
				+ HC_LENGTH(xhci_readl(&(*hccr)->cr_capbase)));

	debug("ltq-xhci: init hccr %x and hcor %x hc_length %d\n",
	      (uint32_t)*hccr, (uint32_t)*hcor,
	      (uint32_t)HC_LENGTH(xhci_readl(&(*hccr)->cr_capbase)));

	return 0;
}

void xhci_hcd_stop(int index)
{
	board_usb_cleanup(index, USB_INIT_HOST);
}

