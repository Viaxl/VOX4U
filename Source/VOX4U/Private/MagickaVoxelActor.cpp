// Copyright 2016 mik14a / Admix Network. All Rights Reserved.

#include "MagickaVoxelActor.h"
#include "VoxelComponent.h"
#include "Voxel.h"

AMagickaVoxelActor::AMagickaVoxelActor(const FObjectInitializer& ObjectInitializer /*= FObjectInitializer::Get()*/)
	: Super(ObjectInitializer)
{
	VoxelComponent = CreateDefaultSubobject<UVoxelComponent>("VoxelComponent");
	VoxelComponent->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);
}

UVoxelComponent* AMagickaVoxelActor::GetVoxelComponent() const
{
	return VoxelComponent;
}
