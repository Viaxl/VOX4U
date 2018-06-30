// Copyright 2016 mik14a / Admix Network. All Rights Reserved.

#include "VoxelActorFactory.h"
#include "Voxel.h"
#include "MagickaVoxelActor.h"
#include "VoxelComponent.h"

UVoxelActorFactory::UVoxelActorFactory(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	DisplayName = NSLOCTEXT("VOX4U", "UVoxelActorFactory", "Voxel Actor");
	NewActorClass = AMagickaVoxelActor::StaticClass();
}

void UVoxelActorFactory::PostSpawnActor(UObject* Asset, AActor* NewActor)
{
	Super::PostSpawnActor(Asset, NewActor);

	AMagickaVoxelActor* VoxelActor = CastChecked<AMagickaVoxelActor>(NewActor);
	UVoxelComponent* VoxelComponent = VoxelActor->GetVoxelComponent();
	check(VoxelComponent);

	if (UVoxel* Voxel = Cast<UVoxel>(Asset)) {
		VoxelComponent->UnregisterComponent();
		VoxelComponent->SetVoxel(Voxel, true);
		VoxelComponent->RegisterComponent();
	}
	VoxelActor->PostEditChange();
}

void UVoxelActorFactory::PostCreateBlueprint(UObject* Asset, AActor* CDO)
{
	if (AMagickaVoxelActor* VoxelActor = Cast<AMagickaVoxelActor>(CDO)) {
		UVoxelComponent* VoxelComponent = VoxelActor->GetVoxelComponent();
		check(VoxelComponent);
		if (UVoxel* Voxel = Cast<UVoxel>(Asset)) {
			VoxelComponent->SetVoxel(Voxel, true);
		}
	}
}

bool UVoxelActorFactory::CanCreateActorFrom(const FAssetData& AssetData, FText& OutErrorMsg)
{
	if (AssetData.IsValid()) {
		UClass* AssetClass = AssetData.GetClass();
		if (AssetClass && AssetClass->IsChildOf(UVoxel::StaticClass())) {
			return true;
		} else {
			OutErrorMsg = NSLOCTEXT("VOX4U", "CanCreateActorFrom_NoVoxel", "No Voxel data specified.");
			return false;
		}
	} else {
		return true;
	}
}
